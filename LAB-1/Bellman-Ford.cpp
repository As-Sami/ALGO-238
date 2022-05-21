
//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_

//  Time   : 2022-05-21 13:19:25

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout << #x << " = " << x << endl

const int inf = 1e9+9;
int dis[1000];
struct edge{
    int x,y,w;

    edge(int x, int y, int w) : x(x), y(y), w(w) {}
};

int main()
{
    int n,m;
    cin >> n >> m;

    for( int i=1 ; i<=n ; i++ )
        dis[i] = inf;

    vector<edge> edges;
    for( int i=0 ; i<m ; i++ )
    {
        int x,y,z;
        cin >> x >> y >> z;
        edges.push_back(edge(x,y,z));
    }

    dis[1] = 0;

    for( int i=0 ; i<n-1 ; i++ )
    {
        for(auto [u,v,w] : edges){
            if( dis[u]+w < dis[v] )
                dis[v] = dis[u] + w;
        }
    }
    
    for( int i=1 ; i<=n ; i++ )
        cout << dis[i] << endl;
    

    
    return 0;
}

