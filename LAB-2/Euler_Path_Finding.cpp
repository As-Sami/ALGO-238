#include <bits/stdc++.h>
using namespace std;

#define print(x) cout << #x << " = " << x << endl

const int N = 1001;
vector<int> g[N];
int vis[N], n;


void dfs(int u){
	vis[u] = 1;
	for(auto v : g[u])
		if( v!=-1 && !vis[v] )
			dfs(v);
}

void remove_edge(int u, int v){
	g[u].erase( find(g[u].begin(), g[u].end(), v) );
	g[v].erase( find(g[v].begin(), g[v].end(), u) );
}

bool check_bridge(int u, int v){

	int cnt = 0;
	memset(vis, 0, sizeof(vis));

	for( int i=1 ; i<=n ; i++ )
		if(!vis[i]){
			dfs(i);
			cnt++;
		}
	
	auto it1 = find(g[u].begin(), g[u].end(), v);
	auto it2 = find(g[v].begin(), g[v].end(), u);

	*it1 = -1;
	*it2 = -1;

	int cntt = 0;
	memset(vis, 0, sizeof(vis));

	for( int i=1 ; i<=n ; i++ )
		if(!vis[i]){
			dfs(i);cntt++;
		}

	if( cnt<cntt ){
		remove_edge(u,-1);
		remove_edge(v,-1);
		return 1;
	}

	*it1 = v;
	*it2 = u;

	return 0;
}


int main()
{
	int m;
	cin >> n >> m;

	vector<int>deg(n+1);

	for( int i=0 ; i<m ; i++ )
	{
		int x,y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
		deg[x]++;
		deg[y]++;
	}

	vector<int> nodes;
	for( int i=1 ; i<=n ; i++ )
		if( deg[i]&1 )
			nodes.push_back(i);

	if( nodes.size()>2 ){
		cout << "impossible" << endl;
	}

	vector<pair<int, int>>ans;

	int u = nodes[0];

	while( ans.size()!=m ){
		int x,y;
		bool flag=1;

		for( auto v : g[u] ){
			cerr << u << ' ' << v << endl;
			
			if( !check_bridge(u,v) ){
				ans.push_back({u,v});
				flag = 0;

cout << "---" <<  u << ' ' << v << endl;


				remove_edge(u,v);
				u = v;

				break;
			}else{

				print(u);
				print(v);

				x = u;
				y = v;

			}
		}

		if(flag){
			ans.push_back({x,y});
			remove_edge(x,y);
			u = y;
		}


		for( int i=1 ; i<=n ; i++ )
		{
			cout << i << " -> ";
			for(auto x : g[i]) cout << x << ' ';
			cout << endl;
		}

	}


	for( int i=1 ; i<=n ; i++ )
	{
		cout << i << " -> ";
		for(auto x : g[i]) cout << x << ' ';
		cout << endl;
	}

		

	for(auto [x,y] : ans )
		cout << x << ' ' << y << endl;
    
    return 0;
}