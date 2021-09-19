#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N*W) [As redundant calculations of states are avoided]
// Auxiliary Space: O(N*W) [The use of 2D array data structure for storing intermediate states]

// array for storing the calculated value
int dp[101][101];

int knapSack(int w, int wt[], int val[], int n) {
   // base case
   if(w == 0 || n == 0) {
       return 0;
   }
   // checking if value is previously calculated or not
   if(dp[n][w] != -1) {
       return dp[n][w];
   }
  
   if(wt[n-1] <= w) {
       // Return the maximum of two cases:
       // (1) nth item included
       // (2) not included
       return dp[n][w] = max(val[n-1] + knapSack(w-wt[n-1], wt, val, n-1), knapSack(w, wt, val, n-1));
   }else {
       // If weight of the nth item is more
       // than Knapsack capacity W, then
       // this item cannot be included
       // in the optimal solution
       return dp[n][w] = knapSack(w, wt, val, n-1);
   }
}


int main() {
    memset(dp, -1, sizeof(dp));
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << knapSack(W, wt, val, n) << "\n";
    
    return 0;
}
