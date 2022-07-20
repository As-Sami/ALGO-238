# Kosaraju's Algo

1. dfs sarbo r ending time count korbo
2. ending time er order e node gula sort korbo( descending order e )
3. Reverse the graph
4. arekta dfs diye ssc check korbo
    
```
    for(auto u : sorted)
        if( !vis[u] )
            dfs(u) -> make all visited node into one SCC
```