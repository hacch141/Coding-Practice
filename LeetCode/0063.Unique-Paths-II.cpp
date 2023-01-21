// 63. Unique Paths II

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
