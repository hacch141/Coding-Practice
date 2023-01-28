// 583. Delete Operation for Two Strings

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> dp(m+1,0), curr(m+1,0);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    curr[j] = 1 + dp[j-1];
                } else {
                    curr[j] = max(curr[j-1],dp[j]);
                }
            }
            dp = curr;
        }
        return m+n-(2*dp[m]);
    }
};
