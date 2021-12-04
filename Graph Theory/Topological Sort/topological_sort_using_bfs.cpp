#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> topo;

void topoSort() {
    int n = adj.size();
    vector<int> indegree(n, 0);
    for(int i=0; i<n; i++) {
        for(auto& it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i<n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        topo.push_back(vertex);
        for(auto& it : adj[vertex]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }   
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n, vector<int>());

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
