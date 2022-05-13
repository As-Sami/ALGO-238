#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1000;
vector<int> g[N];
int dist[N];

void bfs(int u){

    dist[u] = 0;
    queue<int>q;

    q.push(u);

    while(!q.empty()){

        u = q.front();
        q.pop();

        for( auto v : g[u] )
            if( dist[v]==-1 ){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }

}

int main(){

    int n,m;
    cin >> n >> m;

    for( int i=0 ; i<n ; i++ )
        dist[i] = -1;

    for( int i=0 ; i<m ; i++ ){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(3);

    for( int i=0 ; i<n ; i++ )
        cout << i << " -> " << dist[i] << endl;

    return 0;
}
/**
10 9
0 1
0 2
0 3
1 4
1 5
2 6
2 7
3 8
3 9

*/
