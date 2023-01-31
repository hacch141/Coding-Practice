// Recursion
class Solution
{
    private:
    int solve(int idx, int prev, int a[], int n) {
        if(idx == n) return 0;
        int notpick = solve(idx+1,prev,a,n);
        int pick = INT_MIN;
        if(a[idx] > a[prev] || prev == -1) {
            pick = 1+solve(idx+1,idx,a,n);
        }
        return max(pick,notpick);
    }
    
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       return solve(0,-1,a,n);
    }
};



// Memoization
class Solution
{
    private:
    int solve(int idx, int prev, int a[], int n, vector<vector<int>>& dp) {
        if(idx == n) return 0;
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        int notpick = solve(idx+1,prev,a,n,dp);
        int pick = INT_MIN;
        if(a[idx] > a[prev] || prev == -1) {
            pick = 1+solve(idx+1,idx,a,n,dp);
        }
        return dp[idx][prev+1] = max(pick,notpick);
    }
    
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n, vector<int> (n+1,-1));
       return solve(0,-1,a,n,dp);
    }
};



// Tabulation
