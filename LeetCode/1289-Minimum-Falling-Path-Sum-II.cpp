// 1289. Minimum Falling Path Sum II

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = INT_MAX;
        for(int i = 1; i < n; i++) {
            int mn = INT_MAX, mn2 = INT_MAX;
            for(int k = 0; k < m; k++) {
                if(grid[i- 1][k] <= mn) {
                    mn2 = mn;
                    mn = grid[i - 1][k];
                }
                else if(grid[i - 1][k] <= mn2) {
                    mn2 = grid[i - 1][k];
                }
            }

            int mnInd = -1;
            for(int k = 0; k < m; k++) {
                if(mnInd == -1 || grid[i - 1][k] < grid[i - 1][mnInd]) {
                    mnInd = k;
                }
            }

            for(int k = 0; k < m; k++) {
                if(k == mnInd) grid[i][k] += mn2;
                else grid[i][k] += mn;
            }
                
        }

        for(int j = 0; j < m; j++) {
            ans = min(ans, grid[n - 1][j]);
        }
        return ans;
    }
};
