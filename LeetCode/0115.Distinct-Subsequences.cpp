// 115. Distinct Subsequences

// Recursion
class Solution {

private:
    int solve(int n, int m, string& s, string & t) {
        if(m<0) return 1;
        if(n<0) return 0;

        if(s[n] == t[m]) {
            return solve(n-1,m-1,s,t) + solve(n-1,m,s,t);
        }
        return solve(n-1,m,s,t);
    }

public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        return solve(n-1,m-1,s,t);
    }
};

// Memoization
class Solution {

private:
    int solve(int n, int m, string& s, string & t, vector<vector<int>>& dp) {
        if(m<0) return 1;
        if(n<0) return 0;

        if(dp[n][m] != -1) return dp[n][m];
        if(s[n] == t[m]) {
            return dp[n][m] = solve(n-1,m-1,s,t,dp) + solve(n-1,m,s,t,dp);
        }
        return dp[n][m] = solve(n-1,m,s,t,dp);
    }

public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return solve(n-1,m-1,s,t,dp);
    }
};



// Tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<double>> dp(n+1, vector<double> (m+1,0));
        for(int i=0; i<=n; i++) dp[i][0] = 1;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};



// space optimization
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<double> dp(m+1,0),curr(m+1,0);
        dp[0] = 1;
        curr[0] = 1;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == t[j-1]) {
                    curr[j] = dp[j-1] + dp[j];
                } else {
                    curr[j] = dp[j];
                }
            }
            dp = curr;
        }
        return (int)dp[m];
    }
};
