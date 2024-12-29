// 1639. Number of Ways to Form a Target String Given a Dictionary

class Solution {
public:
    int dp[1001][1001];
    const int MOD = 1e9 + 7;

    int solve(int i, int& n, int j, int& m, vector<vector<int>>& freq, string& target) {
        if(j == m) return 1;
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int take = (1LL * freq[i][target[j] - 'a'] * solve(i + 1, n, j + 1, m, freq, target)) % MOD;
        int nottake = solve(i + 1, n, j, m, freq, target) % MOD;
        return dp[i][j] = (take + nottake) % MOD;
    }

    int numWays(vector<string>& words, string target) {
        int n = words[0].size(), m = target.size();
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> freq(n, vector<int>(26, 0));
        for(auto s : words) {
            for(int i = 0; i < n; i++) {
                freq[i][s[i] - 'a']++;
            }
        }
        return solve(0, n, 0, m, freq, target);
    }
};
