#include <bits/stdc++.h>
using namespace std;

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

int main() {
	int set[] = { 1, 2, 3, 7 };
    int n = sizeof(set) / sizeof(set[0]);

	cout << "Minimum subset sum diffrence: " << minimumSubsetSumDiffrence(set, n) << "\n";

	return 0;
}
