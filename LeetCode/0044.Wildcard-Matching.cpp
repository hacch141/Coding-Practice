// 44. Wildcard Matching

// Tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();

        vector<vector<bool>> dp(n+1, vector<bool> (m+1,false));
        dp[0][0] = true;

        for(int j=1; j<=m; j++) {
            dp[0][j] = false;
        }

        for(int i=1; i<=n; i++) {
            bool flag = true;
            for(int k=1; k<=i; k++) {
                if(p[k-1] != '*') flag = false;
            }
            dp[i][0] = flag;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(p[i-1] == s[j-1] || p[i-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*') {
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};


// space optimization
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();

        vector<bool> dp(m+1,false), curr(m+1,false);
        dp[0] = true;

        for(int j=1; j<=m; j++) {
            dp[j] = false;
        }

        for(int i=1; i<=n; i++) {
            bool flag = true;
            for(int k=1; k<=i; k++) {
                if(p[k-1] != '*') flag = false;
            }
            curr[0] = flag;
            for(int j=1; j<=m; j++) {
                if(p[i-1] == s[j-1] || p[i-1] == '?') {
                    curr[j] = dp[j-1];
                }
                else if(p[i-1] == '*') {
                    curr[j] = dp[j] | curr[j-1];
                }
                else {
                    curr[j] = false;
                }
            }
            dp = curr;
        }
        return dp[m];
    }
};
