// 1335. Minimum Difficulty of a Job Schedule

class Solution {
public:

    int solve(int ind, int& n, vector<int>& jobDifficulty, int d, vector<vector<int>>& dp) {
        if(d == 0 && ind == n) return 0;
        if(d == 0 || ind == n) return 1e9;
        
        if(dp[ind][d] != -1) return dp[ind][d];
        
        int ans = 1e9, maxi = 0;
        for(int i=ind; i<n; i++) {
            maxi = max(maxi,jobDifficulty[i]);
            ans = min(ans, maxi + solve(i+1, n, jobDifficulty, d-1, dp));
        }
        
        return dp[ind][d] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d > n) return -1;
        vector<vector<int>> dp(n+1, vector<int>(d+1, -1));
        return solve(0, n, jobDifficulty, d, dp);
    }
};
