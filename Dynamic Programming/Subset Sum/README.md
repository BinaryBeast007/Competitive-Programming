

# *Subset Sum*

**Problem Statement:** Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.   
**Example:**
**Input:** set[] = {3, 34, 4, 12, 5, 2}, sum = 9
**Output:** True  
There is a subset (4, 5) with sum 9.

**Input:** set[] = {3, 34, 4, 12, 5, 2}, sum = 30
**Output:** False
There is no subset that add up to 30.

**Steps:**
If last element is greater than sum, then ignore it. Else, check if sum can be obtained by any of the following:
(a) including the last element
(b) excluding the last element

**Recursive Code:**  
    
````cpp
// Returns true if there is a subset
// of set[] with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum) {
	// Base Cases
	if (sum == 0)
		return true;
	if (n == 0)
		return false;

	// If last element is greater than sum, then ignore it
	if (set[n - 1] > sum)
		return isSubsetSum(set, n - 1, sum);

	/* else, check if sum can be obtained by any of the following:
	(a) including the last element
	(b) excluding the last element */
	return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}
````  

**Memoization**  Top Down  
**Time Complexity:**  O(N\*sum).  
    As redundant calculations of states are avoided.  
**Auxiliary Space:**  O(N\*sum).  
    The use of 2D array data structure for storing intermediate states  
Store the results to avoid the redundant recursive calls.  
````cpp
// Taking the matrix as globally
int dp[2000][2000];

// Check if possible subset with
// given sum is possible or not
int subsetSum(int arr[], int n, int sum) {
	// If the sum is zero it means
	// we got our expected sum
	if (sum == 0) {
		return 1;
	}
	if (n <= 0) {
		return 0;
	}
	// If the value is not -1 it means it
	// already call the function
	// with the same value.
	// it will save our from the repetition.
	if (dp[n - 1][sum] != -1) {
		return dp[n - 1][sum];
	}
	// If last element is greater than sum, we call for the next value
	if (arr[n - 1] > sum) {
		return dp[n - 1][sum] = subsetSum(arr, n - 1, sum);
	}else {
		/* else, check if sum can be obtained by any of the following:
		(a) including the last element
		(b) excluding the last element */
		return dp[n - 1][sum] = subsetSum(arr, n - 1, sum) || subsetSum(arr, n - 1, sum - arr[n - 1]);
	}
}
````  

**Tabulation:** Bottom Up  
 
````cpp
// Returns true if there is a subset of set[]
// with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum) {
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    bool subset[n + 1][sum + 1];
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
    return subset[n][sum];
}
````  

---  
---  
# *Count of subsets with given sum*  
 Given an array **arr[]** of length **N** and an integer **X**, the task is to find the number of subsets with a sum equal to **X**.  
 **Input:**  arr[] = {1, 2, 3, 3}, X = 6  
**Output:**  3  
All the possible subsets are {1, 2, 3},  
{1, 2, 3} and {3, 3}

**Input:**  arr[] = {1, 1, 1, 1}, X = 1  
**Output:**  4  

It's a variation of *Subset Sum* problem. *Subset Sum* states that we have to find a subset with a given sum. Here, *Count of subsets with given sum*, we just have to count such subsets. There's a slight change. We have to store the count in an `int` array and we have to add the number of possible subsets.  

**Tabulation:** Bottom Up  
````cpp
int countSubsetSum(int set[], int n, int sum) {
    int subset[n + 1][sum + 1];
    // If sum is 0, then answer is 1
    for (int i = 0; i <= n; i++) {
        subset[i][0] = 1;
    }
    // If sum is not 0 and set is empty,
    // then answer is 0
    for (int i = 1; i <= sum; i++) {
        subset[0][i] = 0;
    }
    // Fill the subset table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i-1] <= j) {
                subset[i][j] = subset[i - 1][j] + subset[i - 1][j - set[i - 1]];
            }else {
                subset[i][j] = subset[i - 1][j];
            }
        }
    }
    return subset[n][sum];
}
````
