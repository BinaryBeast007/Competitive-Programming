#include <bits/stdc++.h>
using namespace std;

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
int main() {
	int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    cout << "Count of subset sum: " << countSubsetSum(set, n, sum) << "\n";

	return 0;
}
