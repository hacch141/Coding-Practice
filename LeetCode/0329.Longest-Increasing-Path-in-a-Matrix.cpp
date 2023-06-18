// 329. Longest Increasing Path in a Matrix

class Solution {
public:

    int delRow[4] = {-1,0,+1,0};
    int delCol[4] = {0,-1,0,+1};

    bool isValid(int x1, int y1, int x2, int y2, vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(x2<0 || x2>=n || y2<0 || y2>=m) return false;
        return matrix[x1][y1]<matrix[x2][y2];
    }

    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = 1;
        int curr = 1;
        for(int k=0; k<4; k++) {
            int ni = i + delRow[k];
            int nj = j + delCol[k];
            if(isValid(i,j,ni,nj,matrix)) {
                maxi = max(maxi,curr+solve(ni,nj,matrix,dp));
            }
        }
        return dp[i][j] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        int ans = 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans = max(ans,solve(i,j,matrix,dp));
            }
        }
        return ans;
    }
};
