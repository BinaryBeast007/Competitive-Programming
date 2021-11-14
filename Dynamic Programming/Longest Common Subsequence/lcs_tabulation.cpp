#include<bits/stdc++.h>
using namespace std;

int LCS(string str1, int len1, string str2, int len2) {
    int dp[len1+1][len2+1];
    for(int i=0; i<=len1; i++) {
        for(int j=0; j<=len2; j++) {
            if(i==0 || j==0) {
                dp[i][j] = 0;
            }else if(str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[len1][len2];
}

int main() {
    string str1 = "ABCDEF", str2 = "AABD";
    int len1 = str1.length(), len2 = str2.length();
    cout << LCS(str1, len1, str2, len2) << '\n';
    
    return 0;
}
