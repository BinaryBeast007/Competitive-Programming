#include<bits/stdc++.h>
using namespace std;      
#define int long long
#define lc (2 * n)
#define rc ((2 * n) + 1)

const int N = 5e5 + 9;
vector<int> t[4 * N];
int a[N];

void build(int n, int b, int e) {
    if(b == e) {
        t[n].push_back(a[b]);
        return;
    }
    int mid = (b + e) / 2;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    merge(t[lc].begin(), t[lc].end(), t[rc].begin(), t[rc].end(), back_inserter(t[n]));
}

int query(int n, int b, int e, int i, int j, int k) {
    if (i > e || b > j) return 0;   // return appropriate value
    if (i <= b && e <= j) {
        // search appropriate value
        return (t[n].size() - (upper_bound(t[n].begin(), t[n].end(), k) - t[n].begin()));
    }
    int mid = (b + e) / 2;
    return query(lc, b, mid, i, j, k) + query(rc, mid + 1, e, i, j, k);
}

int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int q;
    cin >> q;
    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << query(1, 1, n, l, r, k) << "\n";
    }

    return 0;
}
