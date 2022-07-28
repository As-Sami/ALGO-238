// problme -> https://lightoj.com/problem/not-the-best

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout << #x << " = " << x << endl

#define int long long 
const int N = 5000 + 5, inf = 1e18;
set<pair<int, int>>g[N];
int tt = 1;

void run(){
    
    int n,m;
    cin >> n >> m;
    while(m--){
        int x,y,z;
        cin >> x >> y >> z;
        g[x].insert({z,y});
        g[y].insert({z,x});
    }

    vector<int>dis1(n+1, inf), dis2(n+1, inf);
    priority_queue<pair<int, int>, 
                    vector<pair<int, int>>, 
                    greater<pair<int, int>>>pq;

    dis1[1] = 0;
    pq.push({0, 1});

    while(pq.size()){   
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for(auto [w, v] : g[u]){
            int new_cost = cost + w;
            
            if( new_cost < dis1[v]  )
            {
                dis1[v] = new_cost;
                pq.push({new_cost, v});
            }
            else if( new_cost < dis2[v] )
            {
                dis2[v] = new_cost==dis1[v] ? dis2[v] : new_cost;
                pq.push({new_cost, v});
            }
        }
    }

    // for( int i=1 ; i<=n ; i++ ){
    //     cout << i << " -> " << dis1[i] << " " << dis2[i] << endl;
    // }
    

    cout << "Case " << tt++ << ": " << dis2[n] << endl;
    
    for(int i=1 ; i<=n ; i++)
        g[i].clear();
}

int32_t main()
{
    int t = 1;
    cin >> t;
    
    while( t --> 0 ) 
        run();
    
    return 0;
}
