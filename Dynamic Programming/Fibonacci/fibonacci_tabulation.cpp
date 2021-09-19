#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

#define MAXN 100
int arr[MAXN];

int fib(int n) {
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2; i<=n; i++) {
        arr[i] = arr[i-1] + arr[i-2]; 
    }
    return arr[n];
}

int main() {
    memset(arr, -1, sizeof(arr));
    int n = 7;
    cout << fib(n) << "\n";

    return 0;
}
