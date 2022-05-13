#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<int> g[N];

int main()
{
	int n,m;
	cin >> n >> m;

	vector<int> ind(n+1);
	while(m--){
		int x,y;
		cin >> x >> y;
		g[x].push_back(y);
		ind[y]++;
	}

	queue<int>q;

	for( int i=1 ; i<=n ; i++ )
		if( ind[i]==0 )
			q.push(i);
	

	vector<int> ans;

	while(q.size()){
		int u = q.front();
		ans.push_back(u);
		q.pop();

		for(auto v : g[u]){
			ind[v]--;
			if(ind[v]==0){
				q.push(v);
			}
		}
	}

	for(auto u : ans )
		cout << u << ' ';
	cout << endl;
    
    return 0;
}