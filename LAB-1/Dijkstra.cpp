#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1000, inf=INT_MAX;
vector<pair<int,int>> g[N];
int dist[N];
bool vis[N];

int main(){

    int n,m;
    cin >> n >> m;

    for( int i=1 ; i<=n ; i++ )
        dist[i] = inf;

    for( int i=0 ; i<m ; i++ ){
        int x,y,z;
        cin >> x >> y >> z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }

    priority_queue< pair<int,int>,
             vector<pair<int,int>>,
            greater<pair<int,int>>
                    >pq;
    dist[1] = 0;
    pq.push({0,1});

    while(!pq.empty()){
        auto [cost, u] = pq.top();
        pq.pop();

        if( vis[u] ) continue;

        vis[u] = 1;

        for(auto [v,w] : g[u]){
            int cur_cost = cost + w;
            if( cur_cost<dist[v] ){
                dist[v] = cur_cost;
                pq.push( { cur_cost, v} );
            }
        }
    }

    for( int i=1 ; i<=n ; i++ )
        cout << i << " -> " << dist[i] << endl;

    return 0;
}
/**
9 10
1 2 2
1 3 3
1 4 1
1 5 4
2 6 2
2 7 1
2 9 5
4 9 4
5 7 3
7 8 5

*/
