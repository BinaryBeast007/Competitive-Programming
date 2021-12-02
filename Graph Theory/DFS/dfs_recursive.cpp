#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> dfs;

void DFS(int node) {
    dfs.push_back(node);
    visited[node] = true;
    for(auto& it : adj[node]) {
        if(!visited[it]) {
            DFS(it);
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
            DFS(i);
        }
    }
    for(auto& i : dfs) {
        cout << i << " ";
    }

    return 0;
}
