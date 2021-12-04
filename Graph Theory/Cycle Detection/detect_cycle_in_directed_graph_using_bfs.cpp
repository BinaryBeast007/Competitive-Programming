#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

bool isCyclic() {
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
    int cnt = 0;
    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        cnt++;
        for(auto& it : adj[vertex]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }   
    if(cnt == n) return false;
    return true;
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

    if(isCyclic()) {
        cout << "Graph contains cycle\n";
    }else {
        cout << "Graph doesn't contain cycle\n";
    }

    return 0;
}
