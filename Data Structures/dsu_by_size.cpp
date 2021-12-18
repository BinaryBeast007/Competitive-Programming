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

int main() {    

    return 0;
}
