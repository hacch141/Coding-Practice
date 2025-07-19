// 1937. Maximum Number of Points with Cost

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, INT_MIN));
        for(int j = 0; j < m; j++) dp[0][j] = points[0][j];
        for(int i = 1; i < n; i++) {
            vector<long long> l_mx(m);
            l_mx[0] = dp[i - 1][0];
            for(int j = 1; j < m; j++) {
                l_mx[j] = max(l_mx[j - 1] - 1, dp[i - 1][j]);
            }

            vector<long long> r_mx(m);
            r_mx[m - 1] = dp[i - 1][m - 1];
            for(int j = m - 2; j >= 0; j--) {
                r_mx[j] = max(r_mx[j + 1] - 1, dp[i - 1][j]);
            }

            for(int j = 0; j < m; j++) {
                dp[i][j] = points[i][j] + max(l_mx[j], r_mx[j]);
            }
        }
        return *max_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
