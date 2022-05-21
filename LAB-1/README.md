# BFS 

1. uses queue as an underlying structure
2. Complexity O(V + E)


# DFS 

1. uses stack as an underlying structure
2. Complexity O(V + E)


# Dijkstra
 
1. uses heap as an underlying structure
2. single source shortest path finding algo
3. Complexity O(V + E log V)
4. doesn't work in negative cycles

# Floyd-Warshall 

1. just 3 for loop, so complexity O(V^3)
2. Lastly Floyd Warshall works for negative edge but no negative cycle
  

# Bellman Ford

1. works on negative edges but fails in negative cycles.