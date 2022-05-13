#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<pair<int,int>> g[N];
vector<array<int, 3>> ans;
int par[N], col[N];

int find_par(int n){
	if( par[n]==n ) return n;

	return par[n] = find_par(par[n]);
}

void merge(int x, int y){

	int u = find_par(x);
	int v = find_par(y);

	if( u!=v )
		par[u] = v;
}

void Prims(int start){

	priority_queue<
		pair<int, pair<int,int> >,
		vector<pair<int, pair<int,int> > >,
		greater<pair<int, pair<int,int> > >
	>pq;

	for(auto [v,w] : g[start]){
		int x = min(start, v);
		int y = max(start, v);
		pq.push({w, {x, y}});
	}
	

	while(pq.size()){
		int z = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if( find_par(x) == find_par(y) ) continue;

		ans.push_back({x,y,z});
		merge(x,y);



		if( col[x]==0 ){
			for(auto [v,w] : g[x] )
				pq.push( { w, { min(x,v) , max(x,v) } } );
			col[x] = 1;
		}

		if( col[y]==0 ){
			for(auto [v,w] : g[y] )
				pq.push( { w, { min(y,v) , max(y,v) } } );
			col[y] =1;
		}
	}
}

int main(){
	int n,m;
	cin >> n >> m;

	for(int i=1 ; i<=n ; i++ )
		par[i] = i;

	while(m--){
		int x,y,z;
		cin >> x >> y >> z;

		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}

	Prims(1);

	int total = 0;
	for(auto [x, y, z] : ans){
		total += z;
		cout << x << ' ' << y << ' ' << z << endl;
	}
	cout << "MST weight = " << total << endl;
}