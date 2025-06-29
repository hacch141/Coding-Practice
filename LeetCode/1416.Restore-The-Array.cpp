// 1416. Restore The Array

class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int ind, int n, string& s, int k, vector<int>& dp) {
        if(ind == n) return 1;
        if(s[ind] == '0') return 0;

        if(dp[ind] != -1) return dp[ind];

        int cnt = 0, curr_ind = ind;
        long long curr = 0;
        for(int i = ind; i < n; i++) {
            curr = (curr * 10) + (s[i] - '0');
            if(curr > k) break;
            cnt = (cnt + solve(i + 1, n, s, k, dp)) % MOD;
        }
        return dp[ind] = cnt;
    }

    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int> dp(n, -1);
        return solve(0, n, s, k, dp);
    }
};
