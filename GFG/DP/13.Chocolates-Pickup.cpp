// Chocolates Pickup

// Memoization
class Solution {
  public:
  
    int solve(int i, int j1, int j2, int& n, int& m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        
        if(j1>=m || j2>=m || j1<0 || j2<0) return -1e9;
        
        if(i==n-1) {
            if(j1==j2) {
                return grid[i][j1];
            }
            else {
                return grid[i][j1] + grid[i][j2];
            }
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxi = INT_MIN;
        for(int dj1=-1; dj1<=1; dj1++) {
            for(int dj2=-1; dj2<=1; dj2++) {
                
                int choco = 0;
                if(j1==j2) choco = grid[i][j1];
                else choco = grid[i][j1] + grid[i][j2];
                
                choco += solve(i+1,j1+dj1,j2+dj2,n,m,grid,dp);
                maxi = max(maxi,choco);
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m,-1)));
        return solve(0,0,m-1,n,m,grid,dp);
    }
};
// T : O(N*M*M)*9
// S : O(N*M*M) + STACK


// ========================================================================================


// Tabulation
class Solution {
  public:
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m,0)));
        
        for(int i=n-1; i>=0; i--) {
            for(int j1=0; j1<m; j1++) {
                for(int j2=0; j2<m; j2++) {
                    
                    if(i==n-1) {
                        if(j1==j2) {
                            dp[i][j1][j2] = grid[i][j1];
                        }
                        else {
                            dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
                        }
                    }
                    else {
                        
                        int maxi = INT_MIN;
                        for(int dj1=-1; dj1<=1; dj1++) {
                            for(int dj2=-1; dj2<=1; dj2++) {
                                
                                int choco = 0;
                                if(j1==j2) choco = grid[i][j1];
                                else choco = grid[i][j1] + grid[i][j2];
                                
                                if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m) {
                                    choco += dp[i+1][j1+dj1][j2+dj2];
                                }
                                else {
                                    choco += -1e8;
                                }
                                maxi = max(maxi,choco);
                                
                            }
                        }
                        dp[i][j1][j2] = maxi;
                    }
                    
                }
            }
        }
        
        return dp[0][0][m-1];
    }
};
// T : O(N*M*M)*9
// S : O(N*M*M)


// ========================================================================================


// Space Optimization
class Solution {
  public:
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<int>> curr(m, vector<int> (m,0));
        vector<vector<int>> prev(m, vector<int> (m,0));
        
        for(int i=n-1; i>=0; i--) {
            for(int j1=0; j1<m; j1++) {
                for(int j2=0; j2<m; j2++) {
                    
                    if(i==n-1) {
                        if(j1==j2) {
                            curr[j1][j2] = grid[i][j1];
                        }
                        else {
                            curr[j1][j2] = grid[i][j1] + grid[i][j2];
                        }
                    }
                    else {
                        
                        int maxi = INT_MIN;
                        for(int dj1=-1; dj1<=1; dj1++) {
                            for(int dj2=-1; dj2<=1; dj2++) {
                                
                                int choco = 0;
                                if(j1==j2) choco = grid[i][j1];
                                else choco = grid[i][j1] + grid[i][j2];
                                
                                if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m) {
                                    choco += prev[j1+dj1][j2+dj2];
                                }
                                else {
                                    choco += -1e8;
                                }
                                maxi = max(maxi,choco);
                                
                            }
                        }
                        curr[j1][j2] = maxi;
                    }
                    
                }
            }
            prev = curr;
        }
        
        return prev[0][m-1];
    }
};
// T : O(N*M*M)*9
// S : O(M*M)
