// 96. Unique Binary Search Trees

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if(n <= 1) return 1;

        if(dp[n] != -1) return dp[n];

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int l = solve(i, dp);
            int r = solve(n - i - 1, dp);
            ans += l * r;
        }
        return dp[n] = ans;
    }

    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
