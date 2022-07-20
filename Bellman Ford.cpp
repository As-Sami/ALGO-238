#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout << #x << " = " << x << endl

const int N = 500, inf = 1e9;

int32_t main()
{
    int n,m;
    cin >> n >> m;

    vector<pair<pair<int, int>,int>>edges;
    for( int i=0 ; i<m ; i++ )
    {
        int x,y,z;
        cin >> x >> y >> z;
        edges.push_back({{x,y}, z});
    }
    
    vector<int>d(n+1, inf);
    d[1] = 0;

    for( int i=0 ; i<m-1 ; i++ )
    {
        for(auto &[e, w] : edges){
            int u = e.first;
            int v = e.second;

            if( d[u] + w < d[v] )
                d[v] = d[u] + w;
        }
    }
    
    for( int i=1 ; i<=n ; i++ )
        cout << i << " -> " << d[i] << endl;
    
    
    return 0;
}
