#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> g[N], r[N];
int st[N], en[N];
bool vis[N];
stack<int> stk;

int t=0;
int ssc[N];

void dfs(int u){

    st[u] = t++;
    vis[u] = 1;

    for(auto v : g[u])
        if( !vis[v] )
            dfs(v);

    stk.push(u);
    en[u] = t++;
}

void dfs2(int u, int lvl){

    ssc[u] = lvl;
    vis[u] = 1;
    for(auto v : r[u])
        if( !vis[v] )
            dfs2(v, lvl);
}

int main()
{
    int n,m;
    cin >> n >> m;

    while(m--){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        r[y].push_back(x);
    }

    dfs(0);
    
    memset(vis, 0, sizeof(vis));

    int lvl = 1;
    while(stk.size()){
        int u = stk.top(); stk.pop();

        if( !vis[u] )
            dfs2(u, lvl++);

    }

    vector<vector<int>> ans(lvl);
    for( int i=0 ; i<n ; i++ )
        ans[ssc[i]].push_back(i);
    

    for( int i=1 ; i<lvl ; i++ , cout << endl )
        for(auto x : ans[i])
            cout << x << ' ';

    
    return 0;
}
