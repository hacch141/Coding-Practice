// 1235. Maximum Profit in Job Scheduling

class Solution {
public:

    int solve(int ind, int& n, vector<vector<int>>& v, vector<int>& dp) {
        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];

        auto it = lower_bound(v.begin(), v.end(), v[ind][1], [](const vector<int>& a, int value) {
            return a[0] < value;
        });
        int nextIndex = it - v.begin();

        int take = v[ind][2] + solve(nextIndex, n, v, dp);
        int nottake = solve(ind+1, n, v, dp);

        return dp[ind] = max(take, nottake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> v(n, vector<int>(3));
        for(int i=0; i<n; i++) {
            v[i][0] = startTime[i];
            v[i][1] = endTime[i];
            v[i][2] = profit[i];
        }
        sort(v.begin(),v.end());
        vector<int> dp(n+1, -1);
        return solve(0, n, v, dp);
    }
};
