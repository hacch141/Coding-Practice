// 2466. Count Ways To Build Good Strings

class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int curr_len, int low, int high, int zero, int one, vector<int>& dp) {
        if(curr_len > high) return 0;

        if(dp[curr_len] != -1) return dp[curr_len];

        int cnt = 0;
        if(curr_len >= low && curr_len <= high) {
            cnt = (1 + cnt) % MOD;
        }
        cnt = (cnt + solve(curr_len + zero, low, high, zero, one, dp)) % MOD;
        cnt = (cnt + solve(curr_len + one, low, high, zero, one, dp)) % MOD;

        return dp[curr_len] = cnt;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return solve(0, low, high, zero, one, dp);
    }
};
