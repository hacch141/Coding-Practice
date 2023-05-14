// Geek Jump

// Memoization
class Solution {
  public:
  
    int solve(int n, vector<int>& height, vector<int>& dp) {
        if(n==0) return 0;
    
        if(dp[n] != -1) return dp[n];
        
        int oneStep = abs(height[n]-height[n-1]) + solve(n-1,height,dp);
        int twoStep = INT_MAX;
        if(n>1) {
            twoStep = abs(height[n]-height[n-2]) + solve(n-2,height,dp);
        }
        
        return dp[n] = min(oneStep,twoStep);
    }
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n,-1);
        return solve(n-1,height,dp);
    }
};
// T : O(N)
// M : O(N)

// ========================================================================================

// Tabulation
class Solution {
  public:
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n,0);
        dp[1] = abs(height[1]-height[0]); // store first differance
        for(int i=2; i<n; i++) {
            int jumpOne = abs(height[i]-height[i-1]) + dp[i-1];
            int jumpTwo = abs(height[i]-height[i-2]) + dp[i-2];
            dp[i] = min(jumpOne,jumpTwo);
        }
        return dp[n-1];
    }
};
// T : O(N)
// M : O(N)

// ========================================================================================

// Space Optimization
class Solution {
  public:
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        if(n==1) return 0;  // if array size is 1 then no jump possible
        int prev2 = 0;
        int prev = abs(height[1]-height[0]);
        for(int i=2; i<n; i++) {
            int jumpOne = abs(height[i]-height[i-1]) + prev;
            int jumpTwo = abs(height[i]-height[i-2]) + prev2;
            int curr = min(jumpOne,jumpTwo);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
// T : O(N)
// M : O(1)
