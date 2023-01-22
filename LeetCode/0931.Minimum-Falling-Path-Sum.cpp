// 931. Minimum Falling Path Sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m,0), curr(m,0);
        for(int i=0; i<m; i++) {
            dp[i] = matrix[n-1][i];
        }
      
        for(int i=n-2; i>=0; i--) {
            for(int j=0; j<m; j++) {
              
                int down = matrix[i][j];
                int leftDG = matrix[i][j];
                int rightDG = matrix[i][j];
              
                down += dp[j];
              
                if(j>0) leftDG += dp[j-1];
                else leftDG += 1e9;
              
                if(j<n-1) rightDG += dp[j+1];
                else rightDG += 1e9;
              
                curr[j] = min(down,min(leftDG,rightDG));
            }
            dp = curr;
        }
        int maxi = 1e9;
        for(int i=0; i<m; i++) maxi = min(maxi,dp[i]);
        return maxi;
    }
};
