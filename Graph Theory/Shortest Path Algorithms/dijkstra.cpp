#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> dist;
vector<bool> visited;

void dijkstra(int src) {
    // priority_queue<dist, node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({dist[src], src});

    while(!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;

        for(auto& it : adj[node]) {
            int next = it.first;
            int nextDist = it.second;
            if(distance + nextDist < dist[next]) {
                dist[next] = distance + nextDist;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    int n, m, src;
    cin >> n >> m >> src;

    adj.assign(n, vector<pair<int, int>>());
    dist.assign(n, INT_MAX);
    visited.assign(n, false);

    for(int i=0; i<m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        --u, --v;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    dijkstra(src);
    for(auto& it : dist) {
        cout << it << " ";
    }

    return 0;
}
