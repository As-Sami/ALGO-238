//     ____     _____         _____     ____     ___  ___   ____
//    / __ \   / ____|       / ____|   / __ \   |   \/   |   ||
//   / /__\ \  \____ \  ---  \____ \  / /__\ \  | |\__/| |   ||
//  /_/    \_\ |_____/       |_____/ /_/    \_\ |_|    |_|  _||_
 
//  Time   : 05-10-2021 | 13:42:10
//  Problem -> https://cses.fi/problemset/task/1672/
//  note : this was not the labwork

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define ll long long
#define output(x) cout << x << endl
#define print(x) cout << #x << " = " << x << endl
 
const ll inf = 1e13;
const int N = 505;
ll g[N][N];
 
int main()
{
    int n,m,q;
    cin >> n >> m >> q;
 
    for( int i=1 ; i<=n ; i++ )
        for( int j=1 ; j<=n ; j++ )
            g[i][j] = i==j ? 0 : inf;
        
 
    for( int i=0 ; i<m ; i++ )
    {
        ll x,y,z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y],z);
        g[y][x] = min(g[y][x],z);
    }
    
    for( int k=1 ; k<=n ; k++ )
        for( int i=1 ; i<=n ; i++ )
            for( int j=1 ; j<=n ; j++ )
                g[i][j] = min( g[i][j] , g[i][k] + g[k][j] );
 
    for( int i=0 ; i<q ; i++ )
    {
        int x,y;
        cin >> x >> y;
        ll ans = g[x][y];
        if(ans==inf) ans=-1;
        output(ans);
    }
    
            
        
    
    
    return 0;
}