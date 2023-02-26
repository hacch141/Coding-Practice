// 72. Edit Distance

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
