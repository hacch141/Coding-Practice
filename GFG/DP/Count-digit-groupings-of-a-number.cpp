// Count digit groupings of a number

// Rec
class Solution {
  public:
  
    int solve(int ind, int n, int prev_sum, string& s, vector<vector<int>>& dp) {
        if(ind == n) return 1;
        
        if(dp[ind][prev_sum] != -1) return dp[ind][prev_sum];
        
        int cnt = 0;
        int curr_sum = 0;
        for(int i = ind; i < n; i++) {
            curr_sum += s[i] - '0';
            if(curr_sum >= prev_sum) {
                cnt += solve(i + 1, n, curr_sum, s, dp);
            }
        }
        return dp[ind][prev_sum] = cnt;
    }
  
    int TotalCount(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(901, -1));
        return solve(0, n, 0, s, dp);
    }
};
