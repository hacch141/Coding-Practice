// 64. Minimum Path Sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m,0);
        for(int i=0; i<n; i++) {
            vector<int> curr(m,0);
            for(int j=0; j<m; j++) {
                if(i==0 && j==0) curr[j] = grid[0][0];
                else {
                    int up = grid[i][j];
                    int left = grid[i][j];
                    if(i>0) up += dp[j];
                    else up += 1e9;
                    if(j>0) left += curr[j-1];
                    else left += 1e9;
                    curr[j] = min(up,left);
                }
            }
            dp = curr;
        }
        return dp[m-1];
    }
};
