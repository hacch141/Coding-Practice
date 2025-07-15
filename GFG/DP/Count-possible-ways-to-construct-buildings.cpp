// Count possible ways to construct buildings

// Bottom Up
class Solution {
  public:
    int MOD = 1e9 + 7;
  
    int TotalWays(int N) {
        // Code here
        vector<vector<long long>> dp(N, vector<long long>(2, -1));
        dp[0][0] = dp[0][1] = 1;
        for(int i = 1; i < N; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][1] = dp[i - 1][0];
        }
        long long ans = (dp[N-1][0] + dp[N-1][1]) % MOD;
        ans = (ans * ans) % MOD;
        return ans;
    }
};

// Rec
class Solution {
  public:
    int MOD = 1e9 + 7;
    
    int solve(int ind, bool can_take, vector<vector<int>>& dp) {
        if(ind == 0) return 1;
        int cnt;
        if(dp[ind][can_take] != -1) return dp[ind][can_take];
        if(can_take) {
            cnt = solve(ind - 1, false, dp);
        }
        else {
            cnt =  (solve(ind - 1, true, dp) + solve(ind - 1, false, dp)) % MOD;
        }
        return dp[ind][can_take] = cnt;
    }
  
    int TotalWays(int N) {
        // Code here
        vector<vector<int>> dp1(N, vector<int>(2, -1));
        vector<vector<int>> dp2(N, vector<int>(2, -1));
        long long ans = (solve(N - 1, true, dp1) + solve(N - 1, false, dp2)) % MOD;
        return (ans * ans) % MOD;
    }
};
