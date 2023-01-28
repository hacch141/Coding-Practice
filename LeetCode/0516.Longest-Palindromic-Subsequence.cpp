// 516. Longest Palindromic Subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int m = n;
        if(n==1) return 1;
        string s2 = s;
        reverse(s2.begin(),s2.end());

        vector<int> dp(m+1,0), curr(m+1,0);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == s2[j-1]) {
                    curr[j] = 1 + dp[j-1];
                } else {
                    curr[j] = max(curr[j-1],dp[j]);
                }
            }
            dp = curr;
        }
        return dp[m];
    }
};
