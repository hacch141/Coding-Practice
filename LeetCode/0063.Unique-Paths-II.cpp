// 63. Unique Paths II

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<int> dp(m,0);
        dp[0] = !obstacleGrid[0][0];
        for(int i=1; i<m; i++) if(obstacleGrid[0][i]==0) dp[i] = dp[i-1];

        for(int i=1; i<n; i++) {
            if(obstacleGrid[i][0]==1) dp[0] = 0;
            for(int j=1; j<m; j++) {
                if(obstacleGrid[i][j]==0) {
                    dp[j] = dp[j] + dp[j-1];
                }
                else dp[j] = 0;
            }
        }

        return dp[m-1];
    }
};

// ==========================================================================================

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int mod = 2*(1e9);
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> dp(m,0);
        for(int i=0; i<n; i++) {
            vector<int> curr(m,0);
            for(int j=0; j<m; j++) {
                if(i==0 && j==0 && obstacleGrid[0][0]==0) curr[j] = 1;
                else if(obstacleGrid[i][j]==1) curr[j] = 0;
                else {
                    int up = 0;
                    int left = 0;
                    if(i>0) up = dp[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = (up+left)%mod;
                }
            }
            dp = curr;
        }
        return dp[m-1];
    }
};
