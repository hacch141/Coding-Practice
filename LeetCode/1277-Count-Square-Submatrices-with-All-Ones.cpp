// 1277. Count Square Submatrices with All Ones

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
