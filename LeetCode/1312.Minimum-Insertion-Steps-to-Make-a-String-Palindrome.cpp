// 1312. Minimum Insertion Steps to Make a String Palindrome


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

    int minInsertions(string s) {
        int n = s.length();
        return n-longestPalindromeSubseq(s);
    }
};


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

    int minInsertions(string s) {
        int n = s.length();
        return n-longestPalindromeSubseq(s);
    }
};
