// 343. Integer Break

class Solution {
public:
    int solve(int n, bool first, vector<vector<int>>& dp) {
        if(n <= 1) return 1;

        if(dp[n][first] != -1) return dp[n][first];

        int mx = 0;
        for(int i = 1; i < n; i++) {
            mx = max(mx, i * (solve(n - i, false, dp)));
        }
        if(!first) mx = max(mx, n);

        return dp[n][first] = mx;
    }

    int integerBreak(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(n, true, dp);
    }
};

// Math
class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;

        int cnt = n / 3;
        if(n % 3 == 1) {
            // use all (cnt-1) 3s and one 4
            return pow(3, cnt - 1) * 4;
        }
        else if(n % 3 == 2) {
            // use all cnt 3s and one 2
            return pow(3, cnt) * 2;
        }
        return pow(3, cnt);
    }
};
