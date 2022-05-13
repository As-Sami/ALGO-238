#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<int> g[N];

int main()
{
	int n,m;
	cin >> n >> m;

	while(m--){
		int x,y;
		cin >> x >> y;
		g[x].push_back(y);
	}

	queue<int>q;
	
    
    return 0;
}