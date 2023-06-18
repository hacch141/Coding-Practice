// 2328. Number of Increasing Paths in a Grid

class Solution {
public:

    int mod = 1e9+7;
    int delRow[4] = {-1,0,+1,0};
    int delCol[4] = {0,-1,0,+1};

    bool isValid(int x1, int y1, int x2, int y2, int& n, int& m, vector<vector<int>>& grid) {
        if(x2<0 || x2>=n || y2<0 || y2>=m) return false;
        return grid[x1][y1]<grid[x2][y2];
    }

    int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(dp[i][j] != -1) return dp[i][j];
        int total = 1;
        for(int k=0; k<4; k++) {
            int ni = i + delRow[k];
            int nj = j + delCol[k];
            if(isValid(i,j,ni,nj,n,m,grid)) {
                total += solve(ni,nj,n,m,grid,dp)%mod;
            }
        }
        return dp[i][j] = total;
    }

    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        long long ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans = (ans+solve(i,j,n,m,grid,dp))%mod;
            }
        }
        return (int)ans;
    }
};
