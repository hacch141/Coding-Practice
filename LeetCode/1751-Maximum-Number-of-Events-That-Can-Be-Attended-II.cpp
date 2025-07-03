// 1751. Maximum Number of Events That Can Be Attended II

class Solution {
public:
    int get_ind(int val, vector<vector<int>>& events) {
        int n = events.size();
        int l = 0, h = n - 1, ind = n;
        while(l <= h) {
            int m = (h - l) / 2 + l;
            if(events[m][0] > val) {
                ind = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ind;
    }

    int solve(int ind, int n, vector<vector<int>>& events, int k, vector<vector<int>>& dp) {
        if(ind >= n || k <= 0) return 0;

        if(dp[ind][k] != -1) return dp[ind][k];

        int nottake = solve(ind + 1, n, events, k, dp);
        int nxt_ind = get_ind(events[ind][1], events);
        int take = events[ind][2] + solve(nxt_ind, n, events, k - 1, dp);

        return dp[ind][k] = max(take, nottake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n =events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(0, n, events, k, dp);
    }
};
