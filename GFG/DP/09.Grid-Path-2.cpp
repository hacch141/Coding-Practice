// Grid Path 2

// Memoization
class Solution {
  public:
  
    int mod = 1e9+7;
  
    int solve(int n, int m, vector<vector<int>>& grid, vector<vector<int>> dp) {
        if(n>=0 && m>=0 && grid[n][m]==1) return 0;
        if(n==0 && m==0) return 1;
        if(n<0 || m<0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        int up = solve(n-1,m,grid,dp);
        int left = solve(n,m-1,grid,dp);
        
        return dp[n][m] = (up+left)%mod;
    }
  
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return solve(n-1,m-1,grid,dp);
    }
};
// T : O(M*N)
// S : O(N*M) + STACK


// ==================================================================================


// Tabulation
class Solution {
  public:
  
    int mod = 1e9+7;
  
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>> dp(n, vector<int> (m,0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                if(i==0 && j==0 && grid[0][0]!=1) {
                    dp[i][j] = 1;
                }
                else if(grid[i][j]==1) {
                    dp[i][j] = 0;
                }
                else {
                    int left=0, up=0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = (up+left)%mod;
                }
                
            }
        }
        return dp[n-1][m-1];
    }
};
// T : O(M*N)
// S : O(N*M) 


// ==================================================================================


// Space Optimization
class Solution {
  public:
  
    int mod = 1e9+7;
  
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        vector<int> prev(m,0), curr(m,0);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                if(i==0 && j==0 && grid[0][0]!=1) {
                    curr[j] = 1;
                }
                else if(grid[i][j]==1) {
                    curr[j] = 0;
                }
                else {
                    int left=0, up=0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = (up+left)%mod;
                }
                
            }
            prev = curr;
        }
        
        return prev[m-1];
    }
};
// T : O(M*N)
// S : O(2*M)


// https://takeuforward.org/data-structure/grid-unique-paths-2-dp-9/
