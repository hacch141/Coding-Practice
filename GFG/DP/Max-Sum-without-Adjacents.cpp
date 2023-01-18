class Solution{
    
private:
    int solve(int idx, int *arr, vector<int>& dp) {
        if(dp[idx] != -1) return dp[idx];
        if(idx==0) return arr[0];
        if(idx<0) return 0;
        int pick = arr[idx] + solve(idx-2,arr,dp);
        int notpick = 0 + solve(idx-1,arr,dp);
        return dp[idx] = max(pick,notpick);
    }
    
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,-1);
	    return solve(n-1,arr,dp);
	}
};


// memoization
class Solution{
    
private:
    int solve(int idx, int *arr, vector<int>& dp) {
        if(dp[idx] != -1) return dp[idx];
        if(idx==0) return arr[0];
        if(idx<0) return 0;
        int pick = arr[idx] + solve(idx-2,arr,dp);
        int notpick = 0 + solve(idx-1,arr,dp);
        return dp[idx] = max(pick,notpick);
    }
    
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,-1);
	    return solve(n-1,arr,dp);
	}
};
