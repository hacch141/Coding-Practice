// 931. Minimum Falling Path Sum

// DP
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

// Rec
class Solution {
public:
    int dp[101][101];

    int solve(int i, int j, int& n, vector<vector<int>>& matrix) {
        if(i == 0) return matrix[i][j];

        if(dp[i][j] != INT_MIN) return dp[i][j];

        int left = INT_MAX, right = INT_MAX;
        int up = solve(i - 1, j, n, matrix);
        if(j - 1 >= 0) left = solve(i - 1, j - 1, n, matrix);
        if(j + 1 < n) right = solve(i - 1, j + 1, n, matrix);

        return dp[i][j] = matrix[i][j] + min(up, min(left, right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dp[i][j] = INT_MIN;
            }
        }

        int ans = INT_MAX;
        for(int j = 0; j < n; j++) {
            ans = min(ans, solve(n - 1, j, n, matrix));
        }
        return ans;
    }
};
