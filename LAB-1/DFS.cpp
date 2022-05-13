#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1000;
vector<int> g[N];
bool vis[N];
int start[N,

void dfs(int u){

    vis[u] = 1;
    for( auto v : g[u] ){
        if( !vis[v] )
            dfs(v);
    }

}

int main(){

    int n,m;
    cin >> n >> m;

    for( int i=0 ; i<m ; i++ ){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int cnt = 0;
    dfs()

    cout << "Connected components : " << cnt << endl;


    return 0;
}
