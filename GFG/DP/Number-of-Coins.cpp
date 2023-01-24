// Recursion
class Solution{
    
    private:
    int solve(int idx, int coins[], int V) {
        if(idx==0) {
            if(V%coins[0] == 0) {
                return V/coins[0];
            }
            return 1e9;
        }
        int notpick = 0 +solve(idx-1, coins, V);
        int pick = INT_MAX;
        if(coins[idx] <= V) {
            pick = 1 + solve(idx,coins,V-coins[idx]);
        }
        return min(pick,notpick);
    }

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int ans = solve(M-1,coins,V);
	    if(ans >= 1e9) return -1;
	    return ans;
	} 
	  
};



// Memoization
class Solution{
    
    private:
    int solve(int idx, int coins[], int V, vector<vector<int>>& dp) {
        if(idx==0) {
            if(V%coins[0] == 0) {
                return V/coins[0];
            }
            return 1e9;
        }
        if(dp[idx][V] != -1) return dp[idx][V];
        int notpick = 0 +solve(idx-1, coins, V, dp);
        int pick = INT_MAX;
        if(coins[idx] <= V) {
            pick = 1 + solve(idx,coins,V-coins[idx], dp);
        }
        return dp[idx][V] = min(pick,notpick);
    }

	public:
	int minCoins(int coins[], int M, int V) 
	{
	    // Your code goes here
	    vector<vector<int>> dp(M, (vector<int> (V+1,-1)));
	    int ans = solve(M-1,coins,V,dp);
	    if(ans >= 1e9) return -1;
	    return ans;
	} 
	  
};



// Tabulation
class Solution{
    
    private:
    int solve(int n, int coins[], int V) {
        vector<vector<int>> dp(n, vector<int> (V+1,0));
        for(int i=0; i<=V; i++) {
            if(i%coins[0]==0) {
                dp[0][i] = i/coins[0];
            }
            else dp[0][i] = 1e9;
        }
        
        for(int i=1; i<n; i++) {
            for(int target=0; target<=V; target++) {
                int notpick = dp[i-1][target];
                int pick = INT_MAX;
                if(coins[i] <= target) {
                    pick = 1+dp[i][target-coins[i]];
                }
                dp[i][target] = min(pick,notpick);
            }
        }
        return dp[n-1][V];
    }

	public:
	int minCoins(int coins[], int M, int V) 
	{
	    // Your code goes here
	    int ans = solve(M,coins,V);
	    if(ans >= 1e9) return -1;
	    return ans;
	} 
	  
};



// space optimization
class Solution{
    
    private:
    int solve(int n, int coins[], int V) {
        vector<int> dp(V+1,0), curr(V+1,0);
        for(int i=0; i<=V; i++) {
            if(i%coins[0]==0) {
                dp[i] = i/coins[0];
            }
            else dp[i] = 1e9;
        }
        
        for(int i=1; i<n; i++) {
            for(int target=0; target<=V; target++) {
                int notpick = dp[target];
                int pick = INT_MAX;
                if(coins[i] <= target) {
                    pick = 1+curr[target-coins[i]];
                }
                curr[target] = min(pick,notpick);
            }
            dp = curr;
        }
        return dp[V];
    }

	public:
	int minCoins(int coins[], int M, int V) 
	{
	    // Your code goes here
	    int ans = solve(M,coins,V);
	    if(ans >= 1e9) return -1;
	    return ans;
	} 
	  
};
