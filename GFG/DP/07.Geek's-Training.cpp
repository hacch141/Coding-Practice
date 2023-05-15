// Geek's Training

// Memoization
class Solution {
  public:
  
    int solve(int n, int task, vector<vector<int>>& points, vector<vector<int>>& dp) {
        if(n==0) {
            int maxpoints = INT_MIN;
            for(int i=0; i<3; i++) {
                if(i!=task) {
                    maxpoints = max(maxpoints,points[n][i]);
                }
            }
            return dp[n][task] = maxpoints;
        }
        
        if(dp[n][task] != -1) return dp[n][task];
        
        int maxpoints = INT_MIN;
        for(int i=0; i<3; i++) {
            if(i!=task) {
                int point = points[n][i] + solve(n-1,i,points,dp);
                maxpoints = max(maxpoints,point);
            }
        }
        return dp[n][task] = maxpoints;
    }
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int> (4,-1));
        return solve(n-1,3,points,dp);
    }
};
// T : O(N*4*3)
// S : O(N*4)


// =================================================================================


// Tabulation
class Solution {
  public:
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int> (4,0));
        for(int act=0; act<4; act++) {
            for(int i=0; i<3; i++) {
                if(i!=act) {
                    dp[0][act] = max(dp[0][act],points[0][i]);
                }
            }
        }
        
        for(int day=1; day<n; day++) {
            for(int act=0; act<4; act++) {
                for(int i=0; i<3; i++) {
                    if(i != act) {
                        int point = points[day][i] + dp[day-1][i];
                        dp[day][act] = max(dp[day][act],point);
                    }
                }
            }
        }
        
        return dp[n-1][3];
    }
};
// T : O(N*4*3)
// S : O(N*4)


// =================================================================================


// Space Optimization
class Solution {
  public:
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<int> dp(4,0), prev(4,0);
        for(int act=0; act<4; act++) {
            for(int i=0; i<3; i++) {
                if(i!=act) {
                    dp[act] = max(dp[act],points[0][i]);
                }
            }
        }
        
        for(int day=1; day<n; day++) {
            for(int act=0; act<4; act++) {
                for(int i=0; i<3; i++) {
                    if(i != act) {
                        int point = points[day][i] + dp[i];
                        prev[act] = max(prev[act],point);
                    }
                }
            }
            dp = prev;
        }
        
        return dp[3];
    }
};
// T : O(N*4*3)
// S : O(4*2)
