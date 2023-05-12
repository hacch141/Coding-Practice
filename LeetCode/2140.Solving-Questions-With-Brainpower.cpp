// 2140. Solving Questions With Brainpower

class Solution {
public:

    long long solve(int i, vector<vector<int>>& questions, int ans, vector<long long>& dp, int &n) {
        if(i >= n) {
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        long long take = ans + questions[i][0] + solve(i+questions[i][1]+1,questions,ans,dp,n);
        long long nottake = ans + solve(i+1,questions,ans,dp,n);
        return dp[i] = max(take,nottake);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1);
        return solve(0,questions,0,dp,n);
    }
};
