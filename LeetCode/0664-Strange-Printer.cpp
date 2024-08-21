// 664. Strange Printer

class Solution {
public:
    int solve(int i, int j, string& s, vector<vector<int>>& dp) {
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int minsteps = INT_MAX;
        for(int k = i; k < j; k++) {
            minsteps = min(minsteps, solve(i, k, s, dp) + solve(k + 1, j, s, dp));
        }
        return dp[i][j] = (s[i] == s[j]) ? minsteps - 1 : minsteps;
    }

    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, s, dp);
    }
};
