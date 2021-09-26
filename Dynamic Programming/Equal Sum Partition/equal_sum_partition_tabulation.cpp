#include <bits/stdc++.h>
using namespace std;

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

int main() {
	int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);

	if (isSubsetSum(set, n, sum)) {
		cout << "Can be divided into two subsets of equal sum";
	}else {
		cout << "Can not be divided into two subsets of equal sum";
	}

	return 0;
}
