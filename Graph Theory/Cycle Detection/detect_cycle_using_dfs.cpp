#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

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
