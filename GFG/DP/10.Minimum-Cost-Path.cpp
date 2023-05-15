// Minimum Cost Path FOR ONLY FOUR WAY(left,up,right,down)
// From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j). 


// https://takeuforward.org/data-structure/minimum-path-sum-in-a-grid-dp-10/

// =====================================================================================================
// =====================================================================================================

// Minimum Cost Path FOR ONLY TWO WAY(left,up)

// Memoization
class Solution
{
    public:
    
    int solve(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(n==0 && m==0) return grid[0][0];
        if(n<0 || m<0) return 1e9;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        int up = grid[n][m] + solve(n-1,m,grid,dp);
        int left = grid[n][m] + solve(n,m-1,grid,dp);
        
        return dp[n][m] = min(up,left);
    }
    
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return solve(n-1,n-1,grid,dp);
    }
};
// T : O(N*M)
// S : O(N*M) + SATCK


// ==========================================================================


// Tabulation
class Solution
{
    public:
    
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m,0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 && j==0) {
                    dp[0][0] = grid[0][0];
                }
                else {
                    int up=grid[i][j], left=grid[i][j];
                    
                    if(i>0) up += dp[i-1][j];
                    else up = 1e9;
                    
                    if(j>0) left += dp[i][j-1];
                    else left = 1e9;
                    
                    dp[i][j] = min(up,left);
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};
// T : O(N*M)
// S : O(N*M)


// ==========================================================================


// Space Optimization
class Solution
{
    public:
    
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m,0), curr(m,0);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 && j==0) {
                    curr[0] = grid[0][0];
                }
                else {
                    int up=grid[i][j], left=grid[i][j];
                    
                    if(i>0) up += prev[j];
                    else up = 1e9;
                    
                    if(j>0) left += curr[j-1];
                    else left = 1e9;
                    
                    curr[j] = min(up,left);
                }
            }
            prev = curr;
        }
        
        return prev[m-1];
    }
};
// T : O(N*M)
// S : O(2*M)
