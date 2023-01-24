// Recursion
class Solution
{
    private:
    int solve(int idx, int W, int wt[], int val[]) {
        if(idx==0) {
            if(wt[0] <= W) return val[0];
            else return 0;
        }
        int notpick = 0 + solve(idx-1,W,wt,val);
        int pick = INT_MIN;
        if(wt[idx] <= W) {
            pick = val[idx] + solve(idx-1,W-wt[idx],wt,val);
        }
        return max(pick,notpick);
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return solve(n-1,W,wt,val);
    }
};



// Memoization
class Solution
{
    private:
    int solve(int idx, int W, int wt[], int val[], vector<vector<int>>& dp) {
        if(idx==0) {
            if(wt[0] <= W) return val[0];
            else return 0;
        }
        if(dp[idx][W] != -1) return dp[idx][W];
        int notpick = 0 + solve(idx-1,W,wt,val,dp);
        int pick = INT_MIN;
        if(wt[idx] <= W) {
            pick = val[idx] + solve(idx-1,W-wt[idx],wt,val,dp);
        }
        return dp[idx][W] = max(pick,notpick);
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n, vector<int>(W+1,-1));
       return solve(n-1,W,wt,val,dp);
    }
};


// Tabulation
class Solution
{
    private:
    int solve(int idx, int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n, vector<int>(W+1,0));
        for(int i=wt[0]; i<=W; i++) {
            dp[0][i] = val[0];
        }
        
        for(int i=1; i<n; i++) {
            for(int target=0; target<=W; target++) {
                int notpick = dp[i-1][target];
                int pick = INT_MIN;
                if(wt[i] <= target) {
                    pick = val[i] + dp[i-1][target-wt[i]];
                }
                dp[i][target] = max(pick,notpick);
            }
        }
        return dp[n-1][W];
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return solve(n-1,W,wt,val,n);
    }
};


// space optimization
class Solution
{
    private:
    int solve(int idx, int W, int wt[], int val[], int n) {
        vector<int> dp(W+1,0), curr(W+1,0);
        for(int i=wt[0]; i<=W; i++) {
            dp[i] = val[0];
        }
        
        for(int i=1; i<n; i++) {
            for(int target=0; target<=W; target++) {
                int notpick = dp[target];
                int pick = INT_MIN;
                if(wt[i] <= target) {
                    pick = val[i] + dp[target-wt[i]];
                }
                curr[target] = max(pick,notpick);
            }
            dp = curr;
        }
        return dp[W];
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return solve(n-1,W,wt,val,n);
    }
};
