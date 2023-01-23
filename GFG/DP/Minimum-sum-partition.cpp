class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int k = 0;
	    for(int i=0; i<n; i++) k += arr[i];
	    vector<bool> dp(k+1,0), curr(k+1,0);
	    dp[0] = curr[0] = true;
	    if(arr[0] <= k) dp[arr[0]] = true;
	    for(int i=1; i<n; i++) {
	        for(int target=1; target<=k; target++) {
	            bool notpick = dp[target];
	            bool pick = false;
	            if(arr[i] <= target) pick = dp[target-arr[i]];
	            curr[target] = pick | notpick;
	        }
	        dp = curr;
	    }
	    int mini = INT_MAX;
	    for(int i=0; i<=k/2; i++) {
	        if(dp[i]) {
	            mini =min(mini, abs((k-i)-i) );
	        }
	    }
	    return mini;
	} 
};
