#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;

bool bipartiteDFS(int src) {
    if(color[src] == -1) {
        color[src] = 1;
    }
    for(auto& it : adj[src]) {
        if(color[it] == -1) {
            color[it] = 1 - color[src];
            if(!bipartiteDFS(it)) {
                return false;
            }
        }else if(color[it] == color[src]) {
            return false;
        }
    } 
    return true;
}
bool checkBipartite() {
    int n = adj.size();
    for(int i=0; i<n; i++) {
        if(color[i] == -1) {
            if(!bipartiteDFS(i)) 
                return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n, vector<int>());
    color.assign(n, -1);

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(checkBipartite()) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }

    return 0;
}
