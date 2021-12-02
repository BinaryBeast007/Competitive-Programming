# *Breadth-first Search*  

Breadth-first search is a graph traversal algorithm. Graph traversal means visiting every vertex and edge exactly once in a well-defined order. BFS is a traversing algorithm where we start traversing from a selected node (source or starting node) and traverse the graph layerwise thus exploring the neighbour nodes (nodes which are directly connected to source node). Then move towards the next-level neighbour nodes.

As the name BFS suggests, we are required to traverse the graph breadthwise as follows:

1.  First move horizontally and visit all the nodes of the current layer
2.  Move to the next layer

![level order traversal](https://he-s3.s3.amazonaws.com/media/uploads/fdec3c2.jpg)

A typical implementation is based on a queue that contains nodes/vertex. At each step, the next node/vertex  
in the queue will be processed.

**Breadth-first Search Algorithm:**   

 1. Start from any vertex  
 2. If the vertex is not visited, call BFS on it  
 3. Push the vertex into a queue and mark it as visited  
 4. While the queue is not empty, pop the front element (vertex) from the queue and start exploring the vertex  
 5. Start visiting the neighbour vertices  
 6. If any of the neighbour vertices is not visited, push it into the queue and mark it as visited  

---  
We need the adjacency list, vector to store visited nodes/vertex and another vector to store bfs traversal.  
 
````cpp
vector<vector<int>> adj;
vector<bool> visited;
vector<int> bfs;
````

BFS 
````cpp
void BFS(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        bfs.push_back(vertex);
        for(auto& it : adj[vertex]) {
            if(!visited[it]) {
                q.push(it);
                visited[it] = true;
            }
        }
    }   
}
````

Visualization  
--

![bfs traversal](https://he-s3.s3.amazonaws.com/media/uploads/0dbec9e.jpg)
