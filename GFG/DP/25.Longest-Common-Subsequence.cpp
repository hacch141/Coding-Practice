// Longest Common Subsequence

// Memoization
class Solution {
    private:
    int solve(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp) {
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(s1[ind1]==s2[ind2]) {
            return dp[ind1][ind2] = 1 + solve(ind1-1,ind2-1,s1,s2,dp);
        } else {
            return dp[ind1][ind2] = max(solve(ind1-1,ind2,s1,s2,dp),solve(ind1,ind2-1,s1,s2,dp));
        }
        return 0;
    }
    
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(x, vector<int> (y,-1));
        return solve(x-1,y-1,s1,s2,dp);
    }
};



// Tabulation
class Solution {
    private:
    int solve(int n, int m, string s1, string s2) {
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        for(int i=0; i<n; i++) dp[i][0] = 0;
        for(int i=0; i<m; i++) dp[0][i] = 0;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s1[i-1]==s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        return solve(x,y,s1,s2);
    }
};



// space optimization
class Solution
{
    private:
    int solve(int n, int m, string s1, string s2) {
        vector<int> dp(m+1,0), curr(m+1,0);
        dp[0] = 0; curr[0] = 0;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s1[i-1]==s2[j-1]) {
                    curr[j] = 1 + dp[j-1];
                } else {
                    curr[j] = max(dp[j],curr[j-1]);
                }
            }
            dp = curr;
        }
        return dp[m];
    }
    
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        return solve(x,y,s1,s2);
    }
};
