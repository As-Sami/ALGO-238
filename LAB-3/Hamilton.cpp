#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<int> graph[N], path;
vector<vector<int>> hamilton;
bool vis[N];

int n, m;

void dfs(int u)
{
    vis[u] = true;
    if(path.size() == n)
    {
        hamilton.push_back(path);
        vis[u] = false;
        return;
    }

    for(int v : graph[u])
    {
        if(!vis[v])
        {
            path.push_back(v);
            dfs(v);
            path.pop_back();
        }
    }
    vis[u] = false;
}

void Hamilton()
{

    for(int i = 1; i <= n; ++i)
    {
        path.push_back(i);
        dfs(i);
        path.pop_back();
    }

}

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    Hamilton();

    if(hamilton.empty())
        cout << "Hamilton Path can't be found\n";
    else
    {
        cout << "Hamilton Path: \n";
        for(auto x : hamilton.front())
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}

