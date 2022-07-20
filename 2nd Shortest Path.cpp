// problme -> https://lightoj.com/problem/not-the-best

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define print(x) cout << #x << " = " << x << endl
#define inf LLONG_MAX
#define all(x) x.begin(),x.end()
const int mod = 1e9+7;



int main()
{
    int t,Case=1;
    cin >> t;
    while(t--)
    {
        ll n,m;
        cin >> n >> m;

        vector<vector<pii > >adj(n+1);
        vector<pii >nodeW(n+1);
        
        for( ll i=0 ; i<n ; i++ )
        {
            nodeW[i+1].first = inf;
            nodeW[i+1].second = inf;
        }

        for( ll i=0 ; i<m ; i++ ){
            ll x,y,z;
            cin >> x >> y >> z;
            adj[x].pb({y,z});
            adj[y].pb({x,z});
        }
        
        priority_queue<pii  , vector<pii > , greater<pii > >pq;

        nodeW[1].first = 0;
        pq.push({0,1});
int  y=0;
        while(!pq.empty())
        {
            ll cst = pq.top().first, node = pq.top().second;
            ll newcost,curNode;
            pq.pop();
           
            // if(curNode==1 && y)
            //     continue;

            // y=1;
            // print(cst);
            for( ll i=0 ; i<adj[node].size() ; i++ )
            {
                newcost = cst + adj[node][i].second;
                curNode= adj[node][i].first;
                // print(curNode);
                // print(newcost);

                if(nodeW[curNode].first==nodeW[curNode].second)
                {
                    nodeW[curNode].first = newcost;
                    pq.push({newcost,curNode});
                
                }  
                else if( (nodeW[curNode].first >= nodeW[curNode].second 
                       && nodeW[curNode].second >= newcost ) 
                                    ||
                       (  nodeW[curNode].first>=newcost 
                       && newcost>=nodeW[curNode].second ) )
                {
                    nodeW[curNode].first = newcost;
                    pq.push({newcost,curNode});
                }
                else if( (nodeW[curNode].second>=nodeW[curNode].second 
                      &&  nodeW[curNode].first >= newcost)
                                    ||
                          nodeW[curNode].second>=newcost 
                      &&  newcost >= nodeW[curNode].first)
                {
                    nodeW[curNode].second = newcost;
                    pq.push({newcost,curNode});
                }
                
            }
        }
        // print(nodeW[n].first);
        // print(nodeW[n].second);
        cout << "Case " << Case++ << ": "<< max(nodeW[n].second,nodeW[n].first) << endl;
    }
    return 0;
}