// 2742. Painting the Walls

class Solution {
public:
    int solve(int ind, int n, int remain, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp) {
        if(remain <= 0) return 0;
        if(ind == n) return 1e9;

        if(dp[ind][remain] != -1) return dp[ind][remain];

        // -1 for paid paint + (- time[ind]) for free paints
        int paint = cost[ind] + solve(ind + 1, n, remain - 1 - time[ind], cost, time, dp);
        // skip this wall maybe paint in some free paints
        int no_paint = solve(ind + 1, n, remain, cost, time, dp);
        return dp[ind][remain] = min(paint, no_paint);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, n, n, cost, time, dp);
    }
};
