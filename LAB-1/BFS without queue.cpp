#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1000;
vector<int> g[N];

void bfs( int u, int prev){



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

    bfs(0, -1);

    return 0;
}
