// 97. Interleaving String

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
      
        int m = s1.length();
        int n = s2.length();
        int l = s3.length();
      
        if((m+n)!=l) {
            return false;
        }
        
        bool dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
      
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
              
                if(i==0 && j==0) {
                    dp[i][j] = true;
                }
              
                else if(i==0) {
                    if(s2[j-1]==s3[j-1]) {
                        dp[i][j] = dp[i][j-1];
                    }
                }
              
                else if(j==0) {
                    if(s1[i-1]==s3[i-1]) {
                        dp[i][j] = dp[i-1][j];
                    }
                }
              
                else if(s1[i-1]==s3[i+j-1] && s2[j-1]!=s3[i+j-1]) {
                    dp[i][j] = dp[i-1][j];
                }
              
                else if(s2[j-1]==s3[i+j-1] && s1[i-1]!=s3[i+j-1]) {
                    dp[i][j] = dp[i][j-1];
                }
              
                else if(s1[i-1]==s3[i+j-1] && s2[j-1]==s3[i+j-1]) {
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
