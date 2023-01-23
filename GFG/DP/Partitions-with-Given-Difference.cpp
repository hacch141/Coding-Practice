// Partitions with Given Difference

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
