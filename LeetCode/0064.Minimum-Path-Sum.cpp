// 64. Minimum Path Sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m,0);
        vector<int> curr(m,0);

        prev[0] = grid[0][0];
        for(int i=1; i<m; i++) {
            prev[i] = prev[i-1] + grid[0][i];
        }

        for(int i=1; i<n; i++) {
            curr[0] = prev[0] + grid[i][0];
            for(int j=1; j<m; j++) {
                curr[j] = min(curr[j-1],prev[j]) + grid[i][j];
            }
            prev = curr;
        }

        return prev[m-1];
    }
};

// =======================================================================

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m,0));

        dp[0][0] = grid[0][0];
        for(int i=1; i<n; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i=1; i<m; i++) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[n-1][m-1];
    }
};

// ==============================================================================

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
