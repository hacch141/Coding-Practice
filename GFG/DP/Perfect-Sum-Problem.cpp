class Solution{
    
    int mod = (int)1e9+7;
    private:
    int solve(int idx, int sum, int arr[], int n, vector<vector<int>> &dp) {
        if(idx==0) {
            if(sum==0 && arr[0]==0) return 2;
            if(sum==arr[0] || sum==0) return 1;
            return 0;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int notpick = solve(idx-1,sum,arr,n,dp);
        int pick = 0;
        if(arr[idx] <= sum) pick = solve(idx-1,sum-arr[idx],arr,n,dp);
        return dp[idx][sum] = (pick+notpick)%mod;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return solve(n-1,sum,arr,n,dp);
	}
};
