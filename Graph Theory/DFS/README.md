# *Depth-first Search*  

Depth-first search is a graph traversal algorithm. Graph traversal means visiting every vertex and edge exactly once in a well-defined order. Depth first Search or Depth first traversal is a recursive algorithm for searching all the vertices of a graph or tree data structure.  Depth first search (DFS) algorithm starts with the initial node of the graph G, and then goes to deeper and deeper until we find the goal node or the node which has no children. The algorithm, then backtracks from the dead end towards the most recent node that is yet to be completely unexplored.  

**Depth-first Search Algorithm (Recursive):**  

 1. Start from any vertex  
 2. If the vertex is not visited, call DFS on it  
 3. Mark it as visited and call DFS recursively on it's unvisited neighbour vertices  
---  
We need the adjacency list, vector to store visited nodes/vertex and another vector to store dfs traversal.  
 
````cpp
vector<vector<int>> adj;
vector<bool> visited;
vector<int> dfs;
````

DFS 
````cpp
void DFS(int node) {
    dfs.push_back(node);
    visited[node] = true;
    for(auto& it : adj[node]) {
        if(!visited[it]) {
            DFS(it);
        }
    }
}
````  

This recursive nature of DFS can be implemented using stacks.  
**Depth-first Search Algorithm (Iterative):**  

  1. Start from any vertex  
 2. If the vertex is not visited, call DFS on it  
 3. Push the node/vertex into the stack  
 4. While the stck is not empty, pop the top element (vertex) from the stack and if it is not visited, mark it as visited and print as DFS  
 5. Push the unvisited neighbour vertices into the stack  
 
 DFS
 
````cpp
void DFS(int node) {
    stack<int> stk;
    stk.push(node);
    while(!stk.empty()) {
        int vertex = stk.top();
        stk.pop();
        if(!visited[vertex]) {
            visited[vertex] = true;
            dfs.push_back(vertex);
        }
        for(auto& it : adj[vertex]) {
            if(!visited[it]) {
                stk.push(it);
            }
        }
    }
}
````

Visualization  
--

![enter image description here](https://he-s3.s3.amazonaws.com/media/uploads/9fa1119.jpg)
