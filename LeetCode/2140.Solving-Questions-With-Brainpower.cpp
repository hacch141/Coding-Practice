// 2140. Solving Questions With Brainpower

class Solution {
public:
    long long solve(int ind, int n, vector<vector<int>>& questions, vector<long long>& dp) {
        if(ind >= n) return 0;

        if(dp[ind] != -1) return dp[ind];

        long long not_take = solve(ind + 1, n, questions, dp);
        long long take = questions[ind][0] + solve(ind + questions[ind][1] + 1, n, questions, dp);

        return dp[ind] = max(take, not_take);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return solve(0, n, questions, dp);
    }
};

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for(int i = n - 1; i >= 0; i--) {
            int nxt = i + questions[i][1] + 1;
            long long take = questions[i][0] + (nxt < n ? dp[nxt] : 0);
            long long not_take = dp[i + 1];
            dp[i] = max(take, not_take);
        }
        return dp[0];
    }
};
