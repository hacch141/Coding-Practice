// 1235. Maximum Profit in Job Scheduling

class Solution {
public:
    int dp[50001];

    int get_ind(int val, vector<vector<int>>& v) {
        int n = v.size();
        int l = 0, h = n - 1, ind = n;
        while(l <= h) {
            int m = (h - l) / 2 + l;
            if(val <= v[m][0]) {
                ind = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ind;
    }

    int solve(int ind, int& n, vector<vector<int>>& v) {
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int nxt_ind = get_ind(v[ind][1], v);
        int take = v[ind][2] + solve(nxt_ind, n, v);
        int nottake = solve(ind + 1, n, v);
        return dp[ind] = max(take, nottake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(v.begin(), v.end());
        return solve(0, n, v);
    }
};
