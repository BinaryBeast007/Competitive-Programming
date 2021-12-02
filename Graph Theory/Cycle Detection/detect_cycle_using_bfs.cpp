#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

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
    
    if(isCyclic()) {
        cout << "Graph contains cycle\n";
    }else {
        cout << "Graph doesn't contain cycle\n";
    }

    return 0;
}
