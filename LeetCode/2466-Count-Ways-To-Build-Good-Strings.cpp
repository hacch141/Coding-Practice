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

// Iterative
class Solution {
public:
    int MOD = 1e9 + 7;

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        int ans = 0;
        for(int i = 1; i <= high; i++) {
            if(i - zero >= 0) dp[i] = (dp[i] + dp[i - zero]) % MOD;
            if(i - one >= 0) dp[i] = (dp[i] + dp[i - one]) % MOD;
            if(i >= low) ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};
