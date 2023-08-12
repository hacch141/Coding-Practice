// Count all subsequences with sum K

int mod = 1e9+7;

int solve(int i, int sum, vector<int>& arr, vector<vector<int>>& dp) {

	if(i == arr.size()) {
		return sum == 0 ? 1 : 0;
	}

	if(dp[i][sum] != -1) return dp[i][sum];

	int nottake = solve(i+1,sum,arr,dp);
	int take = 0;
	if(arr[i] <= sum) {
		take = solve(i+1,sum-arr[i],arr,dp);
	}

	return dp[i][sum] = (take + nottake) % mod;
}

int findWays(vector<int>& arr, int k) {
	// Write your code here.
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1,-1));
	return solve(0,k,arr,dp);
}

// T : O(n*k)
// S : O(n*k + n STACK)
