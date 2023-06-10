// Coin Change

// Memoization
class Solution {
    
  private:
    long long solve(int idx, int coins[], int n, int sum, vector<vector<long>>& dp) {
        if(idx == 0) return (sum%coins[0]==0);
        if(dp[idx][sum] != -1) return dp[idx][sum];
        long notpick = solve(idx-1,coins,n,sum,dp);
        long pick = 0;
        if(coins[idx] <= sum) {
            pick = solve(idx,coins,n,sum-coins[idx],dp);
        }
        return dp[idx][sum] = pick + notpick;
    }
    
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long>> dp(N, vector<long> (sum+1,-1));
        return solve(N-1, coins,N,sum,dp);
    }
};



// Tabulation
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long>> dp(N, vector<long> (sum+1,0));
        for(int i=0; i<=sum; i++) {
            if(i%coins[0] == 0) dp[0][i] = 1;
        }
        
        for(int i=1; i<N; i++) {
            for(int target=0; target<=sum; target++) {
                long notpick = dp[i-1][target];
                long pick = 0;
                if(coins[i] <= target) {
                    pick = dp[i][target-coins[i]];
                }
                dp[i][target] = pick + notpick;
            }
        }
        return dp[N-1][sum];
    }
};



// space optimization
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<long> dp(sum+1,0), curr(sum+1,0);
        for(int i=0; i<=sum; i++) {
            if(i%coins[0] == 0) dp[i] = 1;
        }
        
        for(int i=1; i<N; i++) {
            for(int target=0; target<=sum; target++) {
                long notpick = dp[target];
                long pick = 0;
                if(coins[i] <= target) {
                    pick = curr[target-coins[i]];
                }
                curr[target] = pick + notpick;
            }
            dp =curr;
        }
        return dp[sum];
    }
};
