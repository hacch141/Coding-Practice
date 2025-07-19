// 1277. Count Square Submatrices with All Ones

// DP
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j];
                }
                else if(matrix[i][j]){
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};

// Rec
class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(i >= n || j >= m) return 0;
        if(matrix[i][j] == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j + 1, n, m, matrix, dp);
        int diagonal = solve(i + 1, j + 1, n, m, matrix, dp);
        int bottom = solve(i + 1, j, n, m, matrix, dp);

        return dp[i][j] = 1 + min({right, diagonal, bottom});
    }

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans += solve(i, j, n, m, matrix, dp);
            }
        }
        return ans;
    }
};

// Pre calculate the area and use it
class Solution {
public:

    void make_dp(vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < m; j++) {
                dp[i][j] += dp[i][j - 1];
            }
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i][j] += dp[i - 1][j];
            }
        }
    }

    int get_area(int x1, int y1, int x2, int y2, vector<vector<int>>& dp) {
        int area = dp[x2][y2];
        if(x1 - 1 >= 0 && y1 - 1 >= 0) area += dp[x1 - 1][y1 - 1];
        if(x1 - 1 >= 0) area -= dp[x1 - 1][y2];
        if(y1 - 1 >= 0) area -= dp[x2][y1 - 1];
        return area;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<vector<int>> dp = matrix;
        make_dp(matrix, dp);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j]) {
                    ans++;
                    int cnt = 1;
                    while(1) {
                        if(i + cnt < n && j + cnt < m && get_area(i, j, i + cnt, j + cnt, dp) == (cnt + 1) * (cnt + 1)) {
                            cnt++;
                            ans++;
                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
