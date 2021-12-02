#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> bfs;

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

int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n, vector<int>());
    visited.assign(n, false);

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
    for(auto& i : bfs) {
        cout << i << " ";
    }

    return 0;
}
