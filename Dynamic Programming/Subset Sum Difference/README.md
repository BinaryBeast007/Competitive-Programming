

# *Minimum Subset Sum Difference*

**Problem Statement:** Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.  
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.    
**Example:**  
Input:  arr[] = {1, 6, 11, 5}   
Output: 1  
Explanation:  
Subset1 = {1, 5, 6}, sum of Subset1 = 12   
Subset2 = {11}, sum of Subset2 = 11  

**Steps:**
Let, `sum` be the summation of all the elements in the array. We have to divide the array into two subsets `(S1, S2)` such that `abs(S1 - S2)` is minimum possible.   

`S2 - S1 = (sum - S1) - S1`    
`S2 - S1 = sum - 2*S1`  

So, we have to minimize `sum - 2*S1`  
We know, `S1` will be between `0 to sum`. All these possible subsets between `0 to sum` will be in pair. Now, we just have to check between `0 to sum/2` which subset will give us the minimum difference or which value of `sum - 2*S1` is minimum.  


**Tabulation:** Bottom Up   
**Time Complexity: O(n*sum)**
````cpp
bool subset[100][100];
// Returns true if there is a subset of set[]
// with sum equal to given sum
void getSubsetSum(int set[], int n, int sum) {
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++) {
        subset[i][0] = true;
    }
    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++) {
        subset[0][i] = false;
    }
    // Fill the subset table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i-1] <= j) {
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
            }else {
                subset[i][j] = subset[i - 1][j];
            }
        }
    }
}

int minimumSubsetSumDiffrence(int set[], int n) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += set[i];
    }
    getSubsetSum(set, n, sum);

    int minDiff = INT_MAX;
    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 to 0
    for (int j = sum / 2; j >= 0; j--) {
        if (subset[n][j] == true) {
            minDiff = sum - 2 * j;
            break;
        }
    }
    return minDiff;
}
````  
