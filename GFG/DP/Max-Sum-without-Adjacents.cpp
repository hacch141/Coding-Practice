// Recursion
class Solution{
    
private:
    int solve(int idx, int *arr, int n) {
        if(idx == 0) {
            return arr[0];
        }
        if(idx == 1) {
            return max(arr[0],arr[1]);
        }
        int pick = arr[idx] + solve(idx-2,arr,n);
        int notpick = 0 + solve(idx-1,arr,n);
        return max(pick,notpick);
    }
    
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    return solve(n-1,arr,n);
	}
};


// memoization
class Solution{
    
private:
    int solve(int idx, int *arr, int n, vector<int> &dp) {
        if(dp[idx] != -1) return dp[idx];
        int pick = arr[idx] + solve(idx-2,arr,n,dp);
        int notpick = 0 + solve(idx-1,arr,n,dp);
        return dp[idx] = max(pick,notpick);
    }
    
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,-1);
	    dp[0] = arr[0];
	    dp[1] = max(arr[0],arr[1]);
	    return solve(n-1,arr,n,dp);
	}
};

// Tabulation
class Solution{
    
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    if(n==1) return arr[0];
	    vector<int> dp(n,-1);
	    dp[0] = arr[0];
	    dp[1] = max(arr[0],arr[1]);
	    for(int i=2; i<n; i++) {
	        int pick = arr[i] + dp[i-2];
	        int notpick = 0 + dp[i-1];
	        dp[i] = max(pick,notpick);
	    }
	    return dp[n-1];
	}
};


// space optimization
class Solution{
    
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    if(n==1) return arr[0];
	    int prev2 = arr[0];
	    int prev = max(arr[0],arr[1]);
	    for(int i=2; i<n; i++) {
	        int pick = arr[i] + prev2;
	        int notpick = 0 + prev;
	        int curr = max(pick,notpick);
	        prev2 = prev;
	        prev = curr;
	    }
	    return prev;
	}
};
