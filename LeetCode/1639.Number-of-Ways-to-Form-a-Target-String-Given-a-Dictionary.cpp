// 1639. Number of Ways to Form a Target String Given a Dictionary

class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int ind, int n, int ind_tar, string& target, vector<vector<int>>& f, vector<vector<int>>& dp) {
        if(ind_tar == target.length()) return 1;
        if(ind == n) return 0;

        if(dp[ind][ind_tar] != -1) return dp[ind][ind_tar];

        int take = (1LL * f[ind][target[ind_tar] - 'a'] * solve(ind + 1, n, ind_tar + 1, target, f, dp)) % MOD;
        int not_take = solve(ind + 1, n, ind_tar, target, f, dp);

        return dp[ind][ind_tar] = (take + not_take) % MOD;
    }

    int numWays(vector<string>& words, string target) {
        int n = words.size(), m = words[0].size();

        vector<vector<int>> f(m, vector<int>(26, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                f[j][words[i][j] - 'a']++;
            }
        }

        vector<vector<int>> dp(m, vector<int>(target.length(), -1));
        return solve(0, m, 0, target, f, dp);
    }
};

// iterative
class Solution {
public:
    int MOD = 1e9 + 7;

    int numWays(vector<string>& words, string target) {
        int n = words[0].size(), m = target.length();
        
        vector<vector<int>> f(n, vector<int>(26, 0));
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < n; j++) {
                f[j][words[i][j] - 'a']++;
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                // not_take
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                // take
                if(j > 0) dp[i][j] = (dp[i][j] + (1LL * f[i - 1][target[j - 1] - 'a'] * dp[i - 1][j - 1]) % MOD) % MOD;
            }
        }

        return dp[n][m];
    }
};
