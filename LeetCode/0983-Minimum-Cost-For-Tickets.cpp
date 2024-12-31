// 983. Minimum Cost For Tickets

class Solution {
public:
    int  dp[366];

    int get_ind(int n_days, int ind, vector<int>& days) {
        int till_day = days[ind] + n_days;
        int nxt_ind = lower_bound(days.begin(), days.end(), till_day) - days.begin();
        return nxt_ind;
    }

    int solve(int ind, int& n, vector<int>& days, vector<int>& costs) {
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int ind_one = get_ind(1, ind, days);
        int ind_seven = get_ind(7, ind, days);
        int ind_thirty = get_ind(30, ind, days);
        int one = costs[0] + solve(ind_one, n, days, costs);
        int seven = costs[1] + solve(ind_seven, n, days, costs);
        int thirty = costs[2] + solve(ind_thirty, n, days, costs);
        return dp[ind] = min(one, min(seven, thirty));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, days, costs);
    }
};
