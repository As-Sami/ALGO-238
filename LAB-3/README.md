# Fleury’s Algorithm

1. First we have to check if the given graph is eulerian or not.
2. For that the graph have to be connected. Also zero and two vertices
have odd degree. 
3. Now lets start finding the path. First we pick one of the odd vertices.
if no odd vertices found then we take any vertices.
4. After that we take choose an edge that are not bridge. 
If no edge found that is non-bridge then we take any bridge.
5. We add the edge to answer and set current vertex to the next vertex and remove the edge.
6. We stop when we run out of edge.