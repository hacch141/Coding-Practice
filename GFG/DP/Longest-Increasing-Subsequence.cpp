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
class Solution{

    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n+1, vector<int> (n+1,0));
       
       for(int i=n-1; i>=0; i--) {
           for(int prev=i-1; prev>=-1; prev--) {
               int notpick = dp[i+1][prev+1];
               int pick = INT_MIN;
               if(prev==-1 || a[i] > a[prev]) {
                   pick = 1+dp[i+1][i+1];
               }
               dp[i][prev+1] = max(pick,notpick);
           }
       }
       return dp[0][0];
    }
};

// ===================================================
// another one tabulation
class Solution{

    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> dp(n,1);
       int maxi = 1;
       
       for(int i=0; i<n; i++) {
           for(int prev=0; prev<i; prev++) {
               if(a[prev] < a[i]) {
                   dp[i] = max(dp[i],1+dp[prev]);
               }
           }
           maxi = max(maxi,dp[i]);
       }
       return maxi;
    }
};




// ===============================================
// Binary Search
class Solution{

    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> temp;
       int cnt = 1;
       temp.push_back(a[0]);
       for(int i=1; i<n; i++) {
           if(a[i] > temp.back()) {
               temp.push_back(a[i]);
               cnt++;
           } else {
               int idx = lower_bound(temp.begin(),temp.end(),a[i]) - temp.begin();
               temp[idx] = a[i];
           }
       }
       return cnt;
    }
};





// space optimization
class Solution{

    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> dp(n+1,0);
       
       for(int i=n-1; i>=0; i--) {
           for(int prev=i-1; prev>=-1; prev--) {
               int notpick = dp[prev+1];
               int pick = INT_MIN;
               if(prev==-1 || a[i] > a[prev]) {
                   pick = 1+dp[i+1];
               }
               dp[prev+1] = max(pick,notpick);
           }
       }
       return dp[0];
    }
};
