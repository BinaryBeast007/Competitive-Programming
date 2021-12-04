#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> topo;

void findTopoSort(int node, stack<int>& stk) {
    visited[node] = true;
    for(auto& it : adj[node]) {
        if(!visited[it]) {
            findTopoSort(it, stk);
        }
    }
    stk.push(node);
}

void topoSort() {
    stack<int> stk;
    int n = adj.size();
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            findTopoSort(i, stk);
        }
    }
    while(!stk.empty()) {
        topo.push_back(stk.top());
        stk.pop();
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
    }

    topoSort();
    for(auto& i : topo) {
        cout << i << " ";
    }

    return 0;
}
