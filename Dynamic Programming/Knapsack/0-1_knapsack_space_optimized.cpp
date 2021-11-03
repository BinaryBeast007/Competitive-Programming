#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N*W) [As redundant calculations of states are avoided]
// Auxiliary Space: O(W) 

int knapSack(int w, int wt[], int val[], int n) {
    // array for storing the calculated value
    // dp[w+1]
    int dp[w+1] = {0};
    for(int i=0; i<n; i++) {
        for(int j=w; j>=wt[i]; j--) {
            /* maximum of dp[j](excluding ith element value)
            and val[i] + dp[j-wt[i]] (including ith element value and the
            profit with "KnapSack capacity - ith element weight") */
            dp[j] = max(dp[j] , val[i] + dp[j-wt[i]]);
        }
    }
    // Return the maximum value
    return dp[w];
}


int main() {
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << knapSack(W, wt, val, n) << "\n";
    
    return 0;
}
