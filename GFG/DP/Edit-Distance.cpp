// Recursion
class Solution {
    
  private:
    int solve(int i, int j, string& s, string& t) {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(s[i] == t[j]) {
            return solve(i-1,j-1,s,t);
        }
        return 1 + min(solve(i-1,j,s,t) , min(solve(i,j-1,s,t),solve(i-1,j-1,s,t)) );
    }
    
  public:
    int editDistance(string s, string t) {
        // Code here
        int n = s.length();
        int m = t.length();
        return solve(n-1,m-1,s,t);
    }
};



// Memoization
class Solution {
    
  private:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) {
            return dp[i][j] = solve(i-1,j-1,s,t,dp);
        }
        return dp[i][j] = 1 + min(solve(i-1,j,s,t,dp) , min(solve(i,j-1,s,t,dp),solve(i-1,j-1,s,t,dp)) );
    }
    
  public:
    int editDistance(string s, string t) {
        // Code here
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return solve(n-1,m-1,s,t,dp);
    }
};



// Tabulation
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int j=0; j<=m; j++) dp[0][j] = j;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] ==t[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};



// space optimization
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int n = s.length();
        int m = t.length();
        vector<int> dp(m+1,0), curr(m+1,0);
        for(int j=0; j<=m; j++) dp[j] = j;
        
        for(int i=1; i<=n; i++) {
            curr[0] = i;
            for(int j=1; j<=m; j++) {
                if(s[i-1] ==t[j-1]) {
                    curr[j] = dp[j-1];
                }
                else {
                    curr[j] = 1 + min(dp[j], min(curr[j-1],dp[j-1]));
                }
            }
            dp = curr;
        }
        return dp[m];
    }
};
