// 1402. Reducing Dishes

class Solution {
public:

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        
        sort(satisfaction.begin(),satisfaction.end());
        int ans = 0;
        int curr_sum = 0;
        int window = 0;

        for(int i=n-1; i>=0; i--) {
            curr_sum += satisfaction[i];
            window += curr_sum;
            ans = max(ans,window);
        }

        return ans;
    }
};

// ===============================================================================

class Solution {
public:

    int solve(int idx, int mul, vector<int>& satisfaction, int& n, vector<vector<int>>& dp) {
        if(idx==n) return 0;

        if(dp[idx][mul] != -1) return dp[idx][mul];

        int take = satisfaction[idx]*mul + solve(idx+1,mul+1,satisfaction,n,dp);

        int nottake = solve(idx+1,mul,satisfaction,n,dp);

        return dp[idx][mul] = max(take,nottake);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(n, vector<int> (n+1,-1));

        return solve(0,1,satisfaction,n,dp);
    }
};
