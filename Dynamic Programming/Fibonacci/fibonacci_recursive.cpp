#include<iostream>
using namespace std;

// Time Complexity: O(2^n)
// Space Complexity: O(n)

int fib(int n) {
    if(n <= 1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int main() {
    int n = 7;
    cout << fib(n) << "\n";

    return 0;
}
