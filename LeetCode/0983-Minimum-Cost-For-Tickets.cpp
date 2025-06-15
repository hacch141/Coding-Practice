// 983. Minimum Cost For Tickets

// Rec
class Solution {
public:
    int dp[366];

    int get_ind(int val, vector<int>& days) {
        int n = days.size();
        int l = 0, h = n - 1, ans = n;
        while(l <= h) {
            int m = (h - l) / 2 + l;
            if(days[m] >= val) {
                ans = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }

    int solve(int ind, int& n, vector<int>& days, vector<int>& costs) {
        if(ind >= n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int one = costs[0] + solve(ind + 1, n, days, costs);
        int seven = costs[1] + solve(get_ind(days[ind] + 7, days), n, days, costs);
        int thirty = costs[2] + solve(get_ind(days[ind] + 30, days), n, days, costs);

        return dp[ind] = min(one, min(seven, thirty));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, days, costs);
    }
};

// DP
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int last_day = days.back();
        vector<int> dp(last_day + 1, 0);
        unordered_set<int> st(begin(days), end(days));

        for(int i = 1; i <= last_day; i++) {
            if(!st.count(i)) {
                dp[i] = dp[i - 1];
                continue;
            }

            int one = costs[0] + dp[max(0, i - 1)];
            int seven = costs[1] + dp[max(0, i - 7)];
            int thirty = costs[2] + dp[max(0, i - 30)];

            dp[i] = min({one, seven, thirty});
        }

        return dp[last_day];
    }
};
