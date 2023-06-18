// 2713. Maximum Strictly Increasing Cells in a Matrix

// Memoization TLE
class Solution {
public:
    int n,m;

    bool isValid(int x1, int y1, int x2, int y2, vector<vector<int>>& mat) {
        if(x2<0 || x2>=n || y2<0 || y2>=m) return false;
        return mat[x1][y1]<mat[x2][y2];
    }

    int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = 1;
        int curr = 1;
        for(int x=0; x<n; x++) {
            int ni = x;
            int nj = j;
            if(isValid(i,j,ni,nj,mat)) {
                maxi = max(maxi,curr+solve(ni,nj,mat,dp));
            }
        }
        for(int y=0; y<m; y++) {
            int ni = i;
            int nj = y;
            if(isValid(i,j,ni,nj,mat)) {
                maxi = max(maxi,curr+solve(ni,nj,mat,dp));
            }
        }
        return dp[i][j] = maxi;
    }

    int maxIncreasingCells(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        int ans = 1;
        vector<vector<int>> dp(n, vector<int> (m,-1));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans = max(ans,solve(i,j,mat,dp));
            }
        }
        return ans;
    }
};
