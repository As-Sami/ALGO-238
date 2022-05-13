#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int n,m;

vector<int>adj[N];
int disc[N],low[N],vis[N];
stack<int>st;
int t=0;

void tarjan(int u)
{

    disc[u] = low[u] = ++t;
    
    st.push(u);
    vis[u] = 1; 
    for(auto v : adj[u])
    {
        if(disc[v] == -1){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(vis[v]){
            low[u] = min(low[u], disc[v]);
        }
    }
    int w = 0;
    if(low[u] == disc[u])
    {
        while(st.top()!=u)
        {
            w = st.top();
            cout << w << ' ';
            vis[w] = 0;
            st.pop();
        }
        w = st.top();
        cout << w << endl;
        vis[w] = 0;
        st.pop();
    }
}

int main()
{
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    memset(vis,0,sizeof(vis));
    memset(disc,-1,sizeof(disc));
    memset(low,-1,sizeof(low));
    
    for(int i=0;i<n;i++)
    {
        if(disc[i]==-1)
            tarjan(i);

    }
    
    return 0;
}