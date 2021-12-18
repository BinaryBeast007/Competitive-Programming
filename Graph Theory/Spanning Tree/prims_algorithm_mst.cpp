#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<bool> mstSet;
vector<int> key, parent;

int prim(int src) {
    // priority_queue<weight, node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[src] = 0;
    parent[src] = -1;
    pq.push({0, src});
    int minimumCost = 0;
    while(!pq.empty()) {
        auto minCostNode = pq.top();
        pq.pop();
        int node = minCostNode.second;
        int weight = minCostNode.first;
        if(mstSet[node]) {
            continue;
        }
        mstSet[node] = true;
        minimumCost += weight;
        for(auto& it : adj[node]) {
            int u = it.first, wt = it.second;
            if(!mstSet[u] && wt < key[u]) {
                pq.push({wt, u});
                key[u] = wt;
                parent[u] = node;
            }
        }
    }
    for(int i=1; i<adj.size(); i++) {
        cout << parent[i] << " " << i << "\n";
    }
    return minimumCost;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n, vector<pair<int, int>>());
    mstSet.assign(n, false);
    key.assign(n, INT_MAX);
    parent.assign(n, -1);

    for(int i=0; i<m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    cout << prim(0) << "\n";

    return 0;
}
