#include<iostream>
using namespace std;

// Time Complexity: O(2^n) [As there are redundant subproblems}
// Auxiliary Space: O(1) [As no extra data structure has been used for storing values]

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

int main() {
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int w = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << knapSack(w, wt, val, n) << "\n";
    
    return 0;
}
