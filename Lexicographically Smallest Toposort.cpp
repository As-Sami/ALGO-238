// Problem -> https://www.spoj.com/problems/TOPOSORT/en/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 4;
vector<int>g[N];
int indeg[N], col[N];
bool cycle;

void dfs(int u){
    col[u] = 2;
    for(auto v : g[u]){
        if( col[v]==2 )
            cycle = true;
        else if( col[v]==0 )
            dfs(v);
    }
    col[u] = 1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for ( int i = 0 ; i < m ; i++ )
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        indeg[y]++;
    }

    for ( int i = 1 ; i<=n ; i++ )
        if ( col[i]==0 )
            dfs(i);

    priority_queue<int , vector<int> , greater<int> > q;
    for (int i = 1 ; i <= n ; i++ )
        if (indeg[i] == 0)
            q.push(i);


    if (q.empty() || cycle)
        cout << "Sandro fails." << endl;
    else {
        
        vector<int>ans;
        while (!q.empty())
        {
            int node = q.top();
            q.pop();
            ans.push_back(node);

            for (int next : g[node])
            {
                indeg[next]--;
                if (!indeg[next])
                    q.push(next);
            }
        }

        for ( int i = 0 ; i < ans.size() ; i++ )
            cout << ans[i] << " \n"[i == ans.size() - 1];
    }


    return 0;
}