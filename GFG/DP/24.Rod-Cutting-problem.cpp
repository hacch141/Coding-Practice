// Rod Cutting

// Memoization
class Solution{
    
  private:
    int solve(int idx, int price[], int n, vector<vector<int>>& dp) {
        if(idx==0) return n*price[0];
        if(dp[idx][n] != -1) return dp[idx][n];
        int notpick = solve(idx-1,price,n,dp);
        int pick = INT_MIN;
        int len = idx+1;
        if(len <= n) {
            pick = price[idx] + solve(idx,price,n-len,dp);
        }
        return dp[idx][n] = max(pick,notpick);
    }
    
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        return solve(n-1,price,n,dp);
    }
};



// Tabulation
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        
        for(int i=0; i<=n; i++) {
            dp[0][i] = i * price[0];
        }
        
        for(int i=1; i<n; i++) {
            for(int len=0; len<=n; len++) {
                int notpick = 0 + dp[i-1][len];
                int pick = INT_MIN;
                if(i+1 <= len) {
                    pick = price[i] + dp[i][len-(i+1)];
                }
                dp[i][len] = max(pick, notpick);
            }
        }
        return dp[n-1][n];
    }
};



// space optimization
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<int> dp(n+1,0), curr(n+1,0);
        
        for(int i=0; i<=n; i++) {
            dp[i] = i * price[0];
        }
        
        for(int i=1; i<n; i++) {
            for(int len=0; len<=n; len++) {
                int notpick = 0 + dp[len];
                int pick = INT_MIN;
                if(i+1 <= len) {
                    pick = price[i] + curr[len-(i+1)];
                }
                curr[len] = max(pick, notpick);
            }
            dp =curr;
        }
        return dp[n];
    }
};


// only in one array
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<int> dp(n+1,0);
        
        for(int i=0; i<=n; i++) {
            dp[i] = i * price[0];
        }
        
        for(int i=1; i<n; i++) {
            for(int len=0; len<=n; len++) {
                int notpick = 0 + dp[len];
                int pick = INT_MIN;
                if(i+1 <= len) {
                    pick = price[i] + dp[len-(i+1)];
                }
                dp[len] = max(pick, notpick);
            }
        }
        return dp[n];
    }
};
