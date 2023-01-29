class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        vector<vector<int>> dp(m+1, vector<int> (n+1,0));
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(X[i-1] == Y[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        string ans = "";
        int i = m;
        int j = n;
        
        while(i>0 && j>0) {
            if(X[i-1] == Y[j-1]) {
                ans += X[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                ans += X[i-1];
                i--;
            }
            else {
                ans += Y[j-1];
                j--;
            }
        }
        while(i>0) ans += X[--i];
        while(j>0) ans += Y[--j];
        
        return ans.length();
    }
};
