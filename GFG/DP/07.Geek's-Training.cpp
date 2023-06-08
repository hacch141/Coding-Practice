// Geek's Training

// Memoization
class Solution {
  public:
  
    int solve(int idx, int prev, vector<vector<int>>& points, int& n, vector<vector<int>>& dp) {
        if(idx==0) {
            int maxi = 0;
            for(int task=0; task<3; task++) {
                if(task!=prev) {
                    maxi = max(maxi,points[0][task]);
                }
            }
            return dp[0][prev] = maxi;
        }
        if(dp[idx][prev]!=-1) return dp[idx][prev];
        
        int maxi = 0;
        for(int task=0; task<3; task++) {
            if(task!=prev) {
                maxi = max(maxi, (points[idx][task] + solve(idx-1,task,points,n,dp)) );
            }
        }
        return dp[idx][prev] = maxi;
    }
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(4,-1));
        return solve(n-1,3,points,n,dp);
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


// https://takeuforward.org/data-structure/dynamic-programming-ninjas-training-dp-7/
