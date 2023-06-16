// Longest Increasing Subsequence


// Memoization
class Solution
{
    public:
    
    int solve(int idx, int prev, int& n, int a[], vector<vector<int>>& dp) {
        if(idx==n) return 0;
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        
        int nottake = solve(idx+1,prev,n,a,dp);
        int take = -1e9;
        if(prev==-1 || a[idx]>a[prev]) {
            take = 1 + solve(idx+1,idx,n,a,dp);
        }
        
        return dp[idx][prev+1] = max(take,nottake);
    }
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
       // your code here
       vector<vector<int>> dp(n, vector<int> (n+1, -1));
       return solve(0,-1,n,a,dp);
    }
};


// Tabulation
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
       // your code here
       vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
       for(int idx=n-1; idx>=0; idx--) {
           for(int prev=idx-1; prev>=-1; prev--) {
               int nottake = dp[idx+1][prev+1];
               int take = -1e9;
               if(prev==-1 || a[idx]>a[prev]) {
                   take = 1 + dp[idx+1][idx+1];
               }
               dp[idx][prev+1] = max(take,nottake);
           }
       }
       return dp[0][-1+1];
    }
};


// Space Optimization
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
       // your code here
       vector<int> dp(n+1,0), curr(n+1,0);
       for(int idx=n-1; idx>=0; idx--) {
           for(int prev=idx-1; prev>=-1; prev--) {
               int nottake = dp[prev+1];
               int take = -1e9;
               if(prev==-1 || a[idx]>a[prev]) {
                   take = 1 + dp[idx+1];
               }
               curr[prev+1] = max(take,nottake);
           }
           dp = curr;
       }
       return curr[-1+1];
    }
};
