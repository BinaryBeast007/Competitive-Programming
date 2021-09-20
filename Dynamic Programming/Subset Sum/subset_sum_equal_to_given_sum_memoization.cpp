#include <bits/stdc++.h>
using namespace std;

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

int main() {
	// Storing the value -1 to the matrix
	memset(dp, -1, sizeof(dp));
	int n = 5;
	int arr[] = { 1, 5, 3, 7, 4 };
	int sum = 12;

	if (subsetSum(arr, n, sum)) {
		cout << "YES" << endl;
	}else {
		cout << "NO" << endl;
	}

	return 0;
}
