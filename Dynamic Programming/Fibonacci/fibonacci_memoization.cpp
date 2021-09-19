#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

#define MAXN 100
int arr[MAXN];

int fib(int n) {
    if(n <= 1) {
        return n;
    }
    if(arr[n] != -1) {
        return arr[n];
    }
    return arr[n] = fib(n-1) + fib(n-2);
}

int main() {
    memset(arr, -1, sizeof(arr));
    int n = 7;
    cout << fib(n) << "\n";

    return 0;
}
