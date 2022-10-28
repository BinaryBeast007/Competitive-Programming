#include<bits/stdc++.h>
using namespace std;      

const int N = 1e5 + 5, INF = 1e9 + 10;
vector<pair<int, int>> g[N];
vector<int> dist, parent;

void Dijkstra(int src) {
    dist.assign(N, INF);
    parent.assign(N, -1);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while(!pq.empty()) {
        int node = pq.top().second, d_node = pq.top().first;
        pq.pop();
        if(d_node != dist[node]) {
            continue;
        }
        for(auto& edge : g[node]) {
            int child = edge.first, w = edge.second;
            if(dist[node] + w < dist[child]) {
                dist[child] = dist[node] + w;
                parent[child] = node;
                pq.push({dist[child], child});
            }
        }
    }
}

vector<int> get_path(int src, int to) {
    vector<int> path;
    for (int v = to; v != src; v = parent[v]) {
        path.push_back(v);
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}

int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    Dijkstra(1);
    if(dist[n] == INF) {
        cout << -1 << "\n";
    }else {
        auto path = get_path(1, n);
        for(auto& v : path) {
            cout << v << " ";
        }
    }

    return 0;
}
