// 2466. Count Ways To Build Good Strings

class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[200005];

    int solve(int len, int& low, int& high, int& zero, int& one) {
        if(len > high) return 0;
        if(dp[len] != -1) return dp[len];
        int cnt = len >= low;
        cnt += solve(len + zero, low, high, zero, one);
        cnt %= MOD;
        cnt += solve(len + one, low, high, zero, one);
        cnt %= MOD;
        return dp[len] = cnt;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp, -1, sizeof(dp));
        return solve(0, low, high, zero, one);
    }
};
