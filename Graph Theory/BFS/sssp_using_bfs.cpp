// Single Source Shortest Path (SSSP) Using BFS
#include<bits/stdc++.h>
using namespace std;

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

int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n, vector<int>());
    visited.assign(n, false);
    dist.assign(n, 0);
    parent.assign(n, -1);

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            BFS(i);
        }
    }
    cout << "BFS: ";
    for(auto& i : bfs) {
        cout << i << " ";
    }
    cout << "\n";
    // shortest path from the source to some vertex
    int vertex = n-1;
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

    return 0;
}
