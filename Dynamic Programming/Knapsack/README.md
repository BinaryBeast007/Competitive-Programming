

# *0-1 Knapsack*

**Problem Statement:** Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.  
**Example:**
Weight [] = { 10, 20, 30 }  
Value [] = { 60, 100, 120 }  
W = 50  
Solution : 220 → { 100, 120 }  

**Identifying DP:** We have choices and we have to optimize  
**Choice Diagram:**  
[![Dynamic-Programming.png](https://i.postimg.cc/7Y9d8YCn/Dynamic-Programming.png)](https://postimg.cc/N5ypRtkK)  

**Recursive Code:**  
**Time Complexity:**  O(2^n).  
    As there are redundant subproblems.  
**Auxiliary Space: O(1).**  
    As no extra data structure has been used for storing values.  
    
````cpp
int knapSack(int w, int wt[], int val[], int n) {
   // base case
   if(w == 0 || n == 0) {
       return 0;
   }
   if(wt[n-1] <= w) {
       // Return the maximum of two cases:
       // (1) nth item included
       // (2) not included
       return max(val[n-1] + knapSack(w-wt[n-1], wt, val, n-1), knapSack(w, wt, val, n-1));
   }else {
       // If weight of the nth item is more
       // than Knapsack capacity W, then
       // this item cannot be included
       // in the optimal solution
       return knapSack(w, wt, val, n-1);
   }
}
````  

**Memoization**  Top Down  
**Time Complexity:**  O(N\*W).  
    As redundant calculations of states are avoided.  
**Auxiliary Space:**  O(N\*W).  
    The use of 2D array data structure for storing intermediate states  
Store the results to avoid the redundant recursive calls.  
````cpp
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
````  

**Tabulation:** Bottom Up  
 **Time Complexity:**  O(N\*W).  
    where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse   through all weight capacities 1<=w<=W.  
**Auxiliary Space:**  O(N\*W).   
    The use of 2-D array of size ‘N*W’.  
````cpp
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
````  

**Space Optimized 0-1 Knapsack**  
````cpp
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
````

---  
---  
# *Unbounded Knapsack*  
Given a knapsack weight W and a set of n items with certain value vali and weight wti, we need to calculate the maximum amount that could make up this quantity exactly. This is different from classical Knapsack problem, here we are allowed to use unlimited number of instances of an item.  
Here number of items never changes. We always have all items available.  

In 0-1 Knapsack,  
``dp[i][j]  =  max(val[i-1]  + dp[i-1][j-wt[i-1]], dp[i-1][j]);``  

In Unbounded Knapsack,   
``dp[i][j]  =  max(val[i-1]  + dp[i][j-wt[i-1]], dp[i-1][j]);``   

**Tabulation:** Bottom Up  
 **Time Complexity:**  O(N\*W).   
**Auxiliary Space:**  O(N\*W).   
````cpp
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
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
            }else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    // Return the maximum value
    return dp[n][w];
}
````  

**Space Optimized Unbounded Knapsack**  
 **Time Complexity:**  O(N\*W).   
**Auxiliary Space:**  O(W).   
````cpp
int knapSack(int w, int wt[], int val[], int n) {
    int dp[w+1] = {0};
    // Fill dp[] using recursive formula
    for(int i=0; i<=w; i++) {
        for(int j=0; j<n; j++) {
            if(wt[j] <= i) {
                dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
            }
        }
    }
    // Return the maximum value
    return dp[w];
}
````  
