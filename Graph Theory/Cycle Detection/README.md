# **Cycle Detection In Graph**  

### Undirected Graph Using DFS  

**Approach:**  [Depth First Traversal](https://github.com/BinaryBeast007/Competitive-Programming/tree/main/Graph%20Theory/DFS) can be used to detect a cycle in a Graph. DFS for a connected graph produces a tree. There is a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that is joining a node to itself (self-loop) or one of its ancestor in the tree produced by DFS.  To find the back edge to any of its ancestors keep a visited array and if there is a back edge to any visited node then there is a loop and return true.  
-   **Time Complexity:**  O(V+E).  
-  **Space Complexity:**  O(V).  
    
````cpp
bool checkForCycle(int node, int parent) {
    visited[node] = true;
    for(auto& it : adj[node]) {
        if(!visited[it]) {
            if(checkForCycle(it, node))
                return true;
        }else if(it != parent) {
            return true;
        }
    }
    return false;
}

bool isCyclic() {
    int n = adj.size();
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            if(checkForCycle(i, -1)) {
                return true;
            }
        }
    }
    return false;
}
````  

### Undirected Graph Using BFS  

We do a BFS traversal of the given graph. For every visited vertex ‘v’, if there is an adjacent ‘u’ such that u is already visited and u is not a parent of v, then there is a cycle in the graph. If we don’t find such an adjacent for any vertex, we say that there is no cycle.   
-   **Time Complexity:**  O(V+E).  
-  **Space Complexity:**  O(V).  

````cpp
bool checkForCycle(int node) {
    // queue for storing the node and the parent
    queue<pair<int, int>> q;
    visited[node] = true;
    q.push({node, -1});
    while(!q.empty()) {
        int vertex = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto& it : adj[vertex]) {
            if(!visited[it]) {
                visited[it] = true;
                q.push({it, vertex});
            }else if(parent != it) {
                return true;
            }
        }
    }
    return false;
}

bool isCyclic() {
    int n = adj.size();
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            if(checkForCycle(i)) {
                return true;
            }
        }
    }
    return false;
}
````

### Directed Graph Using DFS  

There is a cycle in a graph only if there is a back edge present in the graph.  We need two visited array. One for tracking the visited node and one for tracking the visited node from the same DFS call. If we visit a node which is already visited in the same DFS call, then there is a cycle.   

-   **Time Complexity:**  O(V+E).  
-  **Space Complexity:**  O(V).  

````cpp
bool checkForCycle(int node) {
    visited[node] = true;
    dfsVisited[node] = true;
    for(auto it : adj[node]) {
        if(!visited[it]) {
            if(checkForCycle(it)) 
                return true;
        }else if(dfsVisited[it]) {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

bool isCyclic() {
    int n = adj.size();
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            if(checkForCycle(i)) {
                return true;
            }
        }
    }
    return false;
}
````  

### Directed Graph Using BFS  

-   **Time Complexity:**  O(V+E).  
-  **Space Complexity:**  O(V).  

We can use ***[Kahn's Algorithm](https://github.com/BinaryBeast007/Competitive-Programming/blob/main/Graph%20Theory/Topological%20Sort/topological_sort_using_bfs.cpp)*** for Topological Sorting to find a cycle in a graph. If the given graph is a DAG (Directed Acyclic Graph), then we can find a topological sort. If we can not find any topological sort then the graph contains a cycle.  

````cpp
bool isCyclic() {
    int n = adj.size();
    vector<int> indegree(n, 0);
    for(int i=0; i<n; i++) {
        for(auto& it : adj[i]) {
            indegree[it]++;
        }
    }
    
    queue<int> q;
    for(int i=0; i<n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        cnt++;
        for(auto& it : adj[vertex]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }   
    if(cnt == n) return false;
    return true;
}
````  

