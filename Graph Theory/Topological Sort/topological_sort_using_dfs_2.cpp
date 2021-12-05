#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> topo;

void findTopoSort(int node) {
    visited[node] = true;
    for(auto& it : adj[node]) {
        if(!visited[it]) {
            findTopoSort(it);
        }
    }
    topo.push_back(node);
}

void topoSort() {
    int n = adj.size();
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            findTopoSort(i);
        }
    }
    reverse(topo.begin(), topo.end());
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
    }

    topoSort();
    for(auto& i : topo) {
        cout << i << " ";
    }

    return 0;
}
