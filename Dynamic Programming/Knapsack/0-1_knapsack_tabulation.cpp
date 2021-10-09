#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N*W) [As redundant calculations of states are avoided]
// Auxiliary Space: O(N*W) [The use of 2D array data structure for storing intermediate states]

// array for storing the calculated value
// dp[n][w]
int dp[101][101];

int knapSack(int w, int wt[], int val[], int n) {
    // Build table dp[][] in bottom up manner
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=w; j++) {
            if(i == 0 || j == 0) {
                // row & column initialization
                dp[i][j] = 0;
            }else if(wt[i-1] <= j) {
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    // Return the maximum value
    return dp[n][w];
}


int main() {
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << knapSack(W, wt, val, n) << "\n";
    
    return 0;
}
