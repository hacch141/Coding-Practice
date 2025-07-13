// 746. Min Cost Climbing Stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 1e9);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 0; i < n; i++) {
            if(i > 0) dp[i] = min(dp[i], cost[i] + dp[i - 1]);
            if(i > 1) dp[i] = min(dp[i], cost[i] + dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};

class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int i=2; i<cost.size(); i++) {
            cost[i] += min(cost[i-1], cost[i-2]);
        }
        return min(cost[n-1], cost[n-2]);
    }
};
