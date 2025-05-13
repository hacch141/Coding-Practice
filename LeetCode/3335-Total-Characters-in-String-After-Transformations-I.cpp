// 3335. Total Characters in String After Transformations I

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> f(26, 0);
        for(auto &ch : s) f[ch-'a']++;

        vector<int> dp = f;
        int MOD = 1e9 + 7;
        for(int i = 0; i < t; i++) {
            vector<int> next_dp(26, 0);
            for(int j = 1; j < 26; j++) {
                next_dp[j] = dp[j - 1];
            }
            next_dp[0] = dp[25];
            next_dp[1] += dp[25];
            next_dp[1] %= MOD;
            dp = next_dp;
        }

        int ans = 0;
        for(auto i : dp) {
            ans += i;
            ans %= MOD;
        }

        return ans;
    }
};
