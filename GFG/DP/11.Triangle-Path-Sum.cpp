// Triangle Path Sum

// Memoization
class Solution {
  public:
  
    int solve(int i,int j, int& n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i==n-1) return triangle[n-1][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int below = triangle[i][j] + solve(i+1,j,n,triangle,dp);
        int dg = triangle[i][j] + solve(i+1,j+1,n,triangle,dp);
        
        return dp[i][j] = min(below,dg);
    }
  
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return solve(0,0,n,triangle,dp);
    }
};
// T : O(N*N) 
// S : O(N*N) + STACK


// ===================================================================================


// Tabulation
class Solution {
  public:
  
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        vector<vector<int>> dp(n, vector<int> (n,0));
        for(int i=0; i<n; i++) {
            dp[n-1][i] = triangle[n-1][i];
        }
        
        for(int i=n-2; i>=0; i--) {
            for(int j=0; j<=i; j++) {
              
                int down = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(down,dg);
            }
        }
        
        return dp[0][0];
    }
};
// T : O(N*N) 
// S : O(N*N)


// ===================================================================================


// Space Optimization
class Solution {
  public:
  
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        vector<int> prev(n,0), curr(n,0);
        
        for(int i=0; i<n; i++) {
            prev[i] = triangle[n-1][i];
        }
        
        for(int i=n-2; i>=0; i--) {
            for(int j=0; j<=i; j++) {
              
                int down = triangle[i][j] + prev[j];
                int dg = triangle[i][j] + prev[j+1];
                
                curr[j] = min(down,dg);
            }
            prev = curr;
        }
        
        return prev[0];
    }
};
// T : O(N*N) 
// S : O(N)
