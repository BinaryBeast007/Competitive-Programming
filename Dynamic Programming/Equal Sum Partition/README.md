

# ***Equal Sum Partition***

**Problem Statement:** Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.      
**Example:**
arr[] = {1, 5, 11, 5}  
Output: true   
The array can be partitioned as {1, 5, 5} and {11}
arr[] = {1, 5, 3}  
Output: false   
The array cannot be partitioned into equal sum sets.  

**Steps:**
If sum is odd, there cannot be two subsets with equal sum. Otherwise try to find a subset with sum = sum / 2.  
Prerequisite: [Subset Sum](https://github.com/BinaryBeast007/Competitive-Programming/tree/main/Dynamic%20Programming/Subset%20Sum "Subset Sum")

**Recursive Code:**  
**Time Complexity:** O(2^n)
````cpp
// A utility function that returns true if there is
// a subset of arr[] with sun equal to given sum
bool isSubsetSum(int arr[], int n, int sum) {
	// Base Cases
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;
	// If last element is greater than sum, then
	// ignore it
	if (arr[n - 1] > sum)
		return isSubsetSum(arr, n - 1, sum);
	/* else, check if sum can be obtained by any of
		the following
		(a) including the last element
		(b) excluding the last element
	*/
	return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

// Returns true if arr[] can be partitioned in two
// subsets of equal sum, otherwise false
bool findPartition(int arr[], int n) {
	// Calculate sum of the elements in array
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
    }
	// If sum is odd, there cannot be two subsets
	// with equal sum
	if (sum % 2 != 0) {
		return false;
    }
	// Find if there is subset with sum equal to
	// half of total sum
	return isSubsetSum(arr, n, sum / 2);
}
````  


**Tabulation:** Bottom Up  
 **Time Complexity:**  O(N\*sum).  
**Auxiliary Space:**  O(N\*sum).  

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

// Returns true if arr[] can be partitioned in two
// subsets of equal sum, otherwise false
bool findPartition(int arr[], int n) {
	// Calculate sum of the elements in array
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
    }
	// If sum is odd, there cannot be two subsets
	// with equal sum
	if (sum % 2 != 0) {
		return false;
    }
	// Find if there is subset with sum equal to
	// half of total sum
	return isSubsetSum(arr, n, sum / 2);
}
````  

**Space Optimized**  
 **Time Complexity:**  O(N\*sum).  
**Auxiliary Space:**  O(sum).  
````cpp
bool isSubsetSum(int set[], int n, int sum) {
	bool subset[sum+1] = {0};
	// Initializing with 1 as sum 0 is always possible
    subset[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=sum; j>=set[i]; j--) {
			// Method 1
            subset[j] = subset[j] || subset[j-set[i]];
			// Method 2
			if (subset[j - set[i]] == 1) {
                subset[j] = 1;
			}
        }
    }
    return subset[sum];
}

// Returns true if arr[] can be partitioned in two
// subsets of equal sum, otherwise false
bool findPartition(int arr[], int n) {
	// Calculate sum of the elements in array
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
    }
	// If sum is odd, there cannot be two subsets
	// with equal sum
	if (sum % 2 != 0) {
		return false;
    }
	// Find if there is subset with sum equal to
	// half of total sum
	return isSubsetSum(arr, n, sum / 2);
}
````
