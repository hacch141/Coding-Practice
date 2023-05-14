// Minimal Cost

// Memoization
class Solution {
  public:
  
    int solve(int n, vector<int>& height, int& k, vector<int>& dp) {
        if(n==0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        // try all jumps and store the minimum cost
        int minCost = INT_MAX;
        for(int i=1; i<=k; i++) {
            if(n-i>=0) {
                int cost = abs(height[n]-height[n-i]) + solve(n-i,height,k,dp);
                minCost = min(minCost,cost);
            }
            else {
                break;
            }
        }
        
        return dp[n] = minCost;
    }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n,-1);
        return solve(n-1,height,k,dp);
    }
};
// T : O(N * K) + STACK
// M : O(N)

// ================================================================================

// Tabulation
class Solution {
  public:
  
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n,0);
        for(int i=1; i<n; i++) {
            // try all jumps and store the minimum cost
            int minCost = INT_MAX;
            for(int jump=1; jump<=k; jump++) {
                if(i-jump>=0) {
                    int cost = abs(height[i]-height[i-jump]) + dp[i-jump];
                    minCost = min(minCost,cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[n-1];
    }
};
// T : O(N * K)
// M : O(N)
