// 1143. Longest Common Subsequence

class Solution {

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<int> dp(n2+1,0), curr(n2+1,0);

        for(int i=1; i<=n1; i++) {
            for(int j=1; j<=n2; j++) {
                if(text1[i-1] == text2[j-1]) {
                    curr[j] = 1 + dp[j-1];
                } else {
                    curr[j] = max(dp[j],curr[j-1]);
                }
            }
            dp = curr;
        }
        return dp[n2];
    }
};
