
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


# *Shortest path in an unweighted graph*  

The idea is to traverse the graph using Breadth-First Search Traversal until we reach the end node and print the route by tracing back the path to the start node. As Breadth-First Search traverse is level order traversal, we can calculate the distance of a node `it` as `dist[it] = dist[vertex] + 1`. Here, `vertex` is the parent node and  `it` is the child node. Also, we can update the `parent` array as `parent[it] = vertex` to print the shortest path later on. 

````cpp
vector<vector<int>> adj;
vector<bool> visited;
vector<int> bfs, dist, parent;

void BFS(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    parent[node] = -1;

    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        bfs.push_back(vertex);
        for(auto& it : adj[vertex]) {
            if(!visited[it]) {
                q.push(it);
                visited[it] = true;
                dist[it] = dist[vertex] + 1;
                parent[it] = vertex;
            }
        }
    }   
}
```` 

We don't need the full BFS traversal after we have calculated the distance of the destination node. First, we have to set the distance of destination node as Infinity, `dist[destination] = INF`. So, this can be added to BFS,  

````cpp
while(!q.empty()) {
	int vertex = q.front();
	q.pop();
	bfs.push_back(vertex);
	for(auto& it : adj[vertex]) {
		if(!visited[it]) {
			q.push(it);
			visited[it] = true;
			dist[it] = dist[vertex] + 1;
			parent[it] = vertex;
		}
	}
	if(dist[destination] != INF) {
		break;
	}
}
````  

Print the path.  
````cpp
if(!visited[vertex]) {
    cout << "NO Path Exists\n";
}else {
    vector<int> path;
	for(int v = vertex; v != -1; v = parent[v]) {
		path.push_back(v);
	}
	reverse(path.begin(), path.end());
	cout << "Path: ";
	for(auto v : path) {
		cout << v << " ";
	}
}
````

# *BFS on 2D Grid*  

Given a matrix of size M x N consisting of integers, the task is to traverse the matrix elements using Breadth-First Search traversal. We assume all the cells of the grid as node/vertex. There is an edge between two cells if they share a side. Now, we can perform BFS. 
We need directions for all the adjacent cells/nodes. If we are in a cell `{x, y}`, we can go `{x, y+1}, {x, y-1}, {x-1, y}, {x+1, y}` in these directions.   
````cpp
vector<pair<int, int>> directions = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} }; 
````  
We need a validator to check if the cell coordinates are valid or not, i.e lies within the boundaries of the given Matrix and are unvisited or not.  
````cpp
bool isValid(int x, int y) {
    if(x < 0 || y < 0 || x >= N || y >= M) {
        return false;
    }
    if(visited[x][y]) {
        return false;
    }
    return true;
}
````  

Now, we can perform BFS on the grid.  
````cpp
void BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()) {
        auto point = q.front();
        q.pop();
        for(int i=0; i<directions.size(); i++) {
            int new_row = point.first + directions[i].first;
            int new_col = point.second + directions[i].second;
            if(isValid(new_row, new_col)) {
                q.push({new_row, new_col});
                visited[new_row][new_col] = true;
            }
        }
    }
}
````
