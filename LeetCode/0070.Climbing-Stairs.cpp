// 70. Climbing Stairs

// DP
class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return n;
        int prev = 1;
        int prev2 = 1;
        for(int i=2; i<=n; i++) {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

// 1D dp
class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return n;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

// Rec
class Solution {
public:
    int dp[46];

    int solve(int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = solve(n - 1) + solve(n - 2);
    }

    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};
