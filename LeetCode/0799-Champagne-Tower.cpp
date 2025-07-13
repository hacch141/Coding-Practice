// 799. Champagne Tower

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1, 0));
        dp[0][0] = poured;
        for(int i = 0; i < query_row; i++) {
            for(int j = 0; j <= i; j++) {
                if(dp[i][j] <= 1) continue;
                dp[i + 1][j] += (dp[i][j] - 1) / 2;
                dp[i + 1][j + 1] += (dp[i][j] - 1) / 2;
                dp[i][j] = 1;
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};

class Solution {
public:
    double solve(int poured, int i, int j, vector<vector<double>>& dp) {
        if(i < 0 || j < 0) return 0;
        if(i == 0 && j == 0) return poured;

        if(dp[i][j] != -1) return dp[i][j];

        double l = (solve(poured, i - 1, j - 1, dp) - 1) / 2;
        double r = (solve(poured, i - 1, j, dp) - 1) / 2;

        return dp[i][j] = max(0.0, l) + max(0.0, r);
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1, vector<double>(query_glass + 1, -1));
        return min(1.0, solve(poured, query_row, query_glass, dp));
    }
};
