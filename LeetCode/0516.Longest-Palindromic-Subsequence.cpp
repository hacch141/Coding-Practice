// 516. Longest Palindromic Subsequence


// Recursive
class Solution {
public:

    int helper(int start, int end, string& s, vector<vector<int>>& dp) {

        if(start==end) return 1;
        if(start>end) return 0;

        if(dp[start][end]!=-1) return dp[start][end];

        if(s[start]==s[end]) return 2 + helper(start+1,end-1,s,dp);

        int left = helper(start,end-1,s,dp);
        int right = helper(start+1,end,s,dp);

        return dp[start][end] = max(left,right);
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return helper(0,n-1,s,dp);
    }
};

=======================================================================================
    
    
// Tabulation
class Solution {
public:

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,0));

        for(int len=1; len<=n; len++) {
            for(int start=0; start<=n-len; start++) {
                int end = start+len-1;
                if(len==1) dp[start][end] = 1;
                else if(s[start]==s[end]) dp[start][end] = 2 + dp[start+1][end-1];
                else dp[start][end] = max(dp[start+1][end],dp[start][end-1]);
            }
        }
        
        return dp[0][n-1];
    }
};


=================================================================================


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
