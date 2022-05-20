#include <bits/stdc++.h>
using namespace std;

#define print(x) cout << #x << " = " << x << endl
const int N = 1000;
vector<int>g[N];

void remove_edge(int u, int v){
    g[u].erase( find(g[u].begin(), g[u].end(), v) );
    g[v].erase( find(g[v].begin(), g[v].end(), u) );
}

void dfs(int u, vector<bool> &vis, int x = -1, int y = -1){

    vis[u] = true;

    for(auto v : g[u]){
        if( (x==u and y==v) or (x==v and y==u) ) continue;
        if(!vis[v])
            dfs(v, vis, x, y);
    }
}

bool is_bridge(int n, int x, int y){
    vector<bool> vis(n,0);

    int comp = 0;

    for( int i=0 ; i<n ; i++ ){
        if(vis[i]==0){
            dfs(0, vis);
            comp++;
        }
    }

    vis.resize(n,0);
    int cur_comp = 0;
    for( int i=0 ; i<n ; i++ ){
        if(vis[i]==0){
            dfs(0, vis, x, y);
            cur_comp++;
        }
    }    

    return cur_comp>=comp;
}

int main()
{
    int n,m;
    cin >> n >> m;
    for( int i=0 ; i<m ; i++ )
    {
        int x,y;
        cin >> x >> y;
        // x--,y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    vector<int> node;
    for( int i=0 ; i<n ; i++ )
        if( g[i].size()&1 )
            node.push_back(i);

    if( node.size()>2 or node.size()==1 ){
        cout << "Impossible" << endl;
        return 0;
    }

    int u = node.size() ? node[0] : 0;
    vector<pair<int, int>>ans;

    int a = 0;

    while( ans.size()!=m )
    {   
        int x = -1, y = -1;
        bool f = 0;

        for(auto v : g[u]){
            if( is_bridge(n,u,v) ){
                x = u;
                y = v;
            }else{
                ans.push_back({u,v});
                remove_edge(u,v);
                u = v;
                f = 1;
                break;
            }
        }

        if(f) continue;

        ans.push_back({x,y});
        remove_edge(x,y);
        u = y;
    }

    for(auto [x,y] : ans)
        cout << x << ' ' << y << endl;

    return 0;
}