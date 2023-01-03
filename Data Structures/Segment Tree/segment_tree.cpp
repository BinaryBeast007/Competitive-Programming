#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
int a[N];
struct ST {
    int t[4 * N];
    static const int inf = 1e9;
    ST() {
        memset(t, 0, sizeof t);
    }
    void build(int n, int b, int e) {
        if (b == e) {
            t[n] = a[b];
            return;
        }
        int mid = b + (e - b) / 2, l = 2 * n, r = 2 * n + 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[n] = max(t[l], t[r]); // change this
    }
    void upd(int n, int b, int e, int i, int x) {
        if (b > i || e < i) return;
        if (b == e && b == i) {
            t[n] = x; // update
            return;
        }
        int mid = b + (e - b) / 2, l = 2 * n, r = 2 * n + 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);
        t[n] = max(t[l], t[r]); // change this
    }
    int query(int n, int b, int e, int i, int j) {
        if (b > j || e < i) return -inf; // return appropriate value
        if (b >= i && e <= j) return t[n];
        int mid = b + (e - b) / 2, l = 2 * n, r = 2 * n + 1;
        return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j)); // change this
    }
}t;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 5;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    t.build(1, 1, n); // building the segment tree
    t.upd(1, 1, n, 2, 10); // assiging 10 to the index 2 (a[2] := 10)
    cout << t.query(1, 1, n, 1, 5) << '\n'; // range max query on the segment [1, 5]

    return 0;
}
