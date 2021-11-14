#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int LCS(string str1, int len1, string str2, int len2) {
    // if either of the sequences become empty, 
    // the lcs will be 0 
    if(len1 == 0 || len2 == 0) {
        return 0;
    }
    // check if the state is already calculated or not
    if(dp[len1][len2] != -1) {
        return dp[len1][len2];
    }
    // if the last character of both sequences matches 
    if(str1[len1-1] == str2[len2-1]) {
        // add 1 length and exclude the matching character 
        // from both sequences
        return dp[len1][len2] = 1 + LCS(str1, len1-1, str2, len2-1);
    }
    // if the last character of both sequences doesn't match
    // Return the maximum of two cases:
    // (1) exclude the last character from the first sequence
    //      and include the last character from the second sequence
    // (2) exclude the last character from the second sequence
    //      and include the last character from the first sequence
    return dp[len1][len2] = max(LCS(str1, len1-1, str2, len2), LCS(str1, len1, str2, len2-1));
}

int main() {
    memset(dp, -1, sizeof(dp));
    string str1 = "ABCDEF", str2 = "AABD";
    int len1 = str1.length(), len2 = str2.length();
    cout << LCS(str1, len1, str2, len2) << '\n';
    
    return 0;
}
