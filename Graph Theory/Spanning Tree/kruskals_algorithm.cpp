#include<bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> size, parent;
public:
    DSU(int n) {
        size.assign(n, 1);
        parent.assign(n, 0);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
    }
    int find_set(int v) {
        if(v == parent[v]) {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if(a != b) {
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
struct Node {
    int first_node, second_node, weight;
    Node(int first, int second, int wt) {
        first_node = first;
        second_node = second;
        weight = wt;
    }
};
bool comp(Node& a, Node& b) {
    return a.weight < b.weight;
}
vector<pair<int, int>> mst;
int kruskals_Mst(int N, vector<Node> edge_list) {
    sort(edge_list.begin(), edge_list.end(), comp);
    DSU dsu(N);
    int mst_cost = 0;
    for(auto& edge : edge_list) {
        int wt = edge.weight;
        int u = edge.first_node;
        int v = edge.second_node;

        if(dsu.find_set(u) != dsu.find_set(v)) {
            dsu.union_sets(u, v);
            mst_cost += wt;
            mst.push_back({u, v});
        }
    }
    return mst_cost;
}

int main() {    
    int n, m;
    cin >> n >> m;
    vector<Node> edge_list;
    for(int i=0; i<m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edge_list.push_back(Node(u, v, wt));
    }
    cout << kruskals_Mst(n, edge_list) << "\n";
    for(auto& it : mst) {
        cout << it.first << " " << it.second << "\n";
    }

    return 0;
}
