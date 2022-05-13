#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<int> g[N];

int main()
{
	int n,m;
	cin >> n >> m;

	vector<int> ind(n+1); // 1 based graph
	while(m--){
		int x,y;
		cin >> x >> y;
		g[x].push_back(y);
		ind[y]++;
	}

	priority_queue<int, vector<int>, greater<int> >pq;

	for( int i=1 ; i<=n ; i++ )
		if( ind[i]==0 )
			pq.push(i);
	

	vector<int> ans;

	while(pq.size()){
		int u = pq.top();
		ans.push_back(u);
		pq.pop();

		for(auto v : g[u]){
			ind[v]--;
			if(ind[v]==0){
				pq.push(v);
			}
		}
	}

	for(auto u : ans )
		cout << u << ' ';
	cout << endl;
    
    return 0;
}