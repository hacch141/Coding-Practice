// 1335. Minimum Difficulty of a Job Schedule

class Solution {
public:
    int solve(int ind, int n, vector<int>& jobDifficulty, int d, vector<vector<int>>& dp) {
        if(ind == n) return d == 0 ? 0 : 1e9;
        if(d < 0) return 1e9;

        if(dp[ind][d] != -1) return dp[ind][d];

        int ans = INT_MAX;
        int mx = 0;
        for(int i = ind; i < n; i++) {
            mx = max(mx, jobDifficulty[i]);
            ans = min(ans, mx + solve(i + 1, n, jobDifficulty, d - 1, dp));
        }
        return dp[ind][d] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n, vector<int>(d + 1, -1));
        int ans = solve(0, n, jobDifficulty, d, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};

// Bottom Up
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n, vector<int>(d, 1e9));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < d; j++) {
                int mx = jobDifficulty[i];
                for(int k = i; k >= 0; k--) {
                    mx = max(mx, jobDifficulty[k]);
                    if(j == 0 && k == 0) dp[i][j] = mx;
                    if(k - 1 >= 0 && j - 1 >= 0) dp[i][j] = min(dp[i][j], mx + dp[k - 1][j - 1]);
                }
            }
        }
        return dp[n - 1][d - 1] != 1e9 ? dp[n - 1][d - 1] : -1;
    }
};
