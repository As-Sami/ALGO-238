#include <bits/stdc++.h>
using namespace std;

int par[1005];

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


int main(){
	int n,m;
	cin >> n >> m;

	for(int i=1 ; i<=n ; i++ )
		par[i] = i;

	vector<array<int,3>> v, ans;

	while(m--){
		int x,y,z;
		cin >> x >> y >> z;

		if( x>y )
			swap(x,y);

		v.push_back({z,x,y});
	}

	sort(v.begin(), v.end());

	for(auto [w, x, y] : v){

		if( find_par(x) == find_par(y) ) continue;

		ans.push_back({x,y,w});
		merge(x,y);

	}


	int total = 0;
	for(auto [x, y, z] : ans){
		total += z;
		cout << x << ' ' << y << ' ' << z << endl;
	}
	cout << "MST weight = " << total << endl;
}