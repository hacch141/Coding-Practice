// 72. Edit Distance


// Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));

        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int j=0; j<=m; j++) dp[0][j] = j;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};




// space optimization
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> dp(m+1,0), curr(m+1,0);
        for(int j=0; j<=m; j++) dp[j] = j;

        for(int i=1; i<=n; i++) {
            curr[0] = i;
            for(int j=1; j<=m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    curr[j] = dp[j-1];
                }
                else {
                    curr[j] = 1 + min(dp[j-1], min(dp[j],curr[j-1]));
                }
            }
            dp = curr;
        }
        return dp[m];
    }
};
