// Max Sum without Adjacents

// Memoization
class Solution{
public:	

    int solve(int n, int arr[], vector<int>& dp) {
        if(n==0) return arr[0];
        if(n<0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int take = arr[n] + solve(n-2,arr,dp);
        int nottake = solve(n-1,arr,dp);
        
        return dp[n] = max(take,nottake);
    }

	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,-1);
	    return solve(n-1,arr,dp);
	}
};
// T : O(N)
// S : O(N) + STACK

// =====================================================================================

// Tabulation
class Solution{
public:	

	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,0);
	    dp[0] = arr[0];
	    dp[1] = max(arr[0],arr[1]);
	    for(int i=2; i<n; i++) {
	        int take = arr[i] + dp[i-2];
	        int nottake = dp[i-1];
	        dp[i] = max(take,nottake);
	    }
	    return dp[n-1];
	}
};
// T : O(N)
// S : O(N)

// =====================================================================================

// Tabulation
class Solution{
public:	

	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    if(n==1) return arr[0];
	    int prev2 = arr[0];
	    int prev = max(arr[0],arr[1]);
	    for(int i=2; i<n; i++) {
	        int take = arr[i] + prev2;
	        int nottake = prev;
	        int curr = max(take,nottake);
	        prev2 = prev;
	        prev = curr;
	    }
	    return prev;
	}
};
// T : O(N)
// S : O(1)
