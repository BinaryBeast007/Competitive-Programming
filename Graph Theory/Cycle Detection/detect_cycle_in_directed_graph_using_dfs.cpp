#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited, dfsVisited;

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

int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n, vector<int>());
    visited.assign(n, false);
    dfsVisited.assign(n, false);

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    if(isCyclic()) {
        cout << "Graph contains cycle\n";
    }else {
        cout << "Graph doesn't contain cycle\n";
    }

    return 0;
}
