# *Longest Common Subsequence*

**Problem Statement:** Given two sequences, find the length of longest subsequence present in both of them.    
**Example:**  
Input:  
str1 = ABCDGH  
str2 = AEDFHR  
Output: 3  
Explanation: LCS for input Sequences  
“ABCDGH” and “AEDFHR” is “ADH” of length 3    

**Recursive Code:**  
**Time Complexity:**  O(2^n).  
    As there are redundant subproblems.  
**Auxiliary Space: O(1).**  
    As no extra data structure has been used for storing values.  
    
````cpp
int LCS(string str1, int len1, string str2, int len2) {
    // if either of the sequences become empty, 
    // the lcs will be 0 
    if(len1 == 0 || len2 == 0) {
        return 0;
    }
    // if the last character of both sequences matches 
    if(str1[len1-1] == str2[len2-1]) {
        // add 1 length and exclude the matching character 
        // from both sequences
        return 1 + LCS(str1, len1-1, str2, len2-1);
    }
    // if the last character of both sequences doesn't match
    // Return the maximum of two cases:
    // (1) exclude the last character from the first sequence
    //      and include the last character from the second sequence
    // (2) exclude the last character from the second sequence
    //      and include the last character from the first sequence
    return max(LCS(str1, len1-1, str2, len2), LCS(str1, len1, str2, len2-1));
}
````  

**Memoization**  Top Down  
**Time Complexity:**  O(len1\*len2).  
    As redundant calculations of states are avoided.  
**Auxiliary Space:**  O(len1\*len2).  
    The use of 2D array data structure for storing intermediate states  
Store the results to avoid the redundant recursive calls.  
````cpp
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
````  

**Tabulation:** Bottom Up  
 **Time Complexity:**  O(len1\*len2).  
**Auxiliary Space:**  O(len1\*len2).   
    The use of 2-D array of size (len1\*len2).  
````cpp
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
````  
