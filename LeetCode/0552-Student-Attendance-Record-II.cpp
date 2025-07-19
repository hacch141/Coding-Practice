// 552. Student Attendance Record II

class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int ind, int n, bool prev_abs, int cons_late, vector<vector<vector<int>>>& dp) {
        if(ind == n) return 1;

        if(dp[ind][prev_abs][cons_late] != -1) return dp[ind][prev_abs][cons_late];

        // present
        int cnt = solve(ind + 1, n, prev_abs, 0, dp) % MOD;

        // The student was absent ('A') for strictly fewer than 2 days total
        if(!prev_abs) {
            cnt = (cnt + solve(ind + 1, n, true, 0, dp)) % MOD;
        }

        // The student was never late ('L') for 3 or more consecutive days.
        if(cons_late < 2) {
            cnt = (cnt + solve(ind + 1, n, prev_abs, cons_late + 1, dp)) % MOD;
        }

        return dp[ind][prev_abs][cons_late] = cnt;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, n, false, 0, dp);
    }
};
