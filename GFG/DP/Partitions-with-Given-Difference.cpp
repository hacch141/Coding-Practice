// Partitions with Given Difference

// Recursion
class Solution {

  int mod = (int)1e9+7;
    
  private:
    int solve(int idx, int sum, vector<int>& arr, vector<vector<int>> &dp) {
        if(idx==0) {
            if(sum==0 && arr[0]==0) return 2;
            if(sum==0 || arr[0]==sum) return 1;
            return 0;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int notpick = solve(idx-1,sum,arr,dp);
        int pick = 0;
        if(arr[idx] <= sum) pick = solve(idx-1,sum-arr[idx],arr,dp);
        return dp[idx][sum] = (pick+notpick)%mod;
    }
    
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int k = 0;
        for(auto i : arr) k += i;
        if((k-d)%2 || (k-d)<0) return false;
        int sum = (k-d)/2;
        vector<vector<int>> dp(n, vector<int> (k+1,-1));
        return solve(n-1,sum,arr,dp);
    }
};


// Memoization
class Solution {

  int mod = (int)1e9+7;
    
  private:
    int solve(int sum, vector<int>& arr, int n) {
        vector<vector<int>> dp(n, vector<int> (sum+1,0));
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(arr[0]!=0 && arr[0]<=sum) dp[0][arr[0]] = 1;
        for(int i=1; i<n; i++) {
            for(int target=0; target<=sum; target++) {
                int notpick = dp[i-1][target];
                int pick = 0;
                if(arr[i] <= target) pick = dp[i-1][target-arr[i]];
                dp[i][target] = (pick+notpick)%mod;
            }
        }
        return dp[n-1][sum];
    }
    
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int k = 0;
        for(auto i : arr) k += i;
        if((k-d)%2 || (k-d)<0) return 0;
        int sum = (k-d)/2;
        return solve(sum,arr,n);
    }
};

// Space Optimization
class Solution {

  int mod = (int)1e9+7;
    
  private:
    int solve(int sum, vector<int>& arr, int n) {
        vector<int> dp(sum+1,0), curr(sum+1,0);
        if(arr[0] == 0) dp[0] = 2;
        else dp[0] = 1;
        if(arr[0]!=0 && arr[0]<=sum) dp[arr[0]] = 1;
        for(int i=1; i<n; i++) {
            for(int target=0; target<=sum; target++) {
                int notpick = dp[target];
                int pick = 0;
                if(arr[i] <= target) pick = dp[target-arr[i]];
                curr[target] = (pick+notpick)%mod;
            }
            dp = curr;
        }
        return dp[sum];
    }
    
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int k = 0;
        for(auto i : arr) k += i;
        if((k-d)%2 || (k-d)<0) return 0;
        int sum = (k-d)/2;
        return solve(sum,arr,n);
    }
};
