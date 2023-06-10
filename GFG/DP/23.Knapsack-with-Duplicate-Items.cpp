// Knapsack with Duplicate Items

// Recursion
class Solution{
public:

    int solve(int idx, int W, int val[], int wt[], vector<vector<int>>& dp) {
        if(idx==0) {
            return (int)(W/wt[0])*val[0];
        }
        if(dp[idx][W] != -1) return dp[idx][W];
        int nottake = 0 + solve(idx-1,W,val,wt,dp);
        int take = INT_MIN; 
        if(wt[idx] <= W) take = val[idx] + solve(idx,W-wt[idx],val,wt,dp);
        return dp[idx][W] = max(take,nottake);
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(W+1,-1));
        return solve(N-1,W,val,wt,dp);
    }
};



// Tabulation
class Solution{
public:

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(W+1,0));
        for(int w=0; w<=W; w++) {
            dp[0][w] = (w/wt[0])*val[0];
        }
        for(int idx=1; idx<N; idx++) {
            for(int w=0; w<=W; w++) {
                int nottake = 0 + dp[idx-1][w];
                int take = INT_MIN;
                if(wt[idx] <= w)take = val[idx] + dp[idx][w-wt[idx]];
                dp[idx][w] = max(take,nottake);
            }
        }
        return dp[N-1][W];
    }
};



// Space Optimization
class Solution{
public:

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int> curr(W+1,0), prev(W+1,0);
        for(int w=0; w<=W; w++) {
            prev[w] = (w/wt[0])*val[0];
        }
        for(int idx=1; idx<N; idx++) {
            for(int w=0; w<=W; w++) {
                int nottake = 0 + prev[w];
                int take = INT_MIN;
                if(wt[idx] <= w)take = val[idx] + curr[w-wt[idx]];
                curr[w] = max(take,nottake);
            }
            prev = curr;
        }
        return prev[W];
    }
};


// 1D Array
class Solution{
public:

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int> curr(W+1,0);
        for(int w=0; w<=W; w++) {
            curr[w] = (w/wt[0])*val[0];
        }
        for(int idx=1; idx<N; idx++) {
            for(int w=0; w<=W; w++) {
                int nottake = 0 + curr[w];
                int take = INT_MIN;
                if(wt[idx] <= w)take = val[idx] + curr[w-wt[idx]];
                curr[w] = max(take,nottake);
            }
        }
        return curr[W];
    }
};
