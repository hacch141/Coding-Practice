// 552. Student Attendance Record II

class Solution {
public:

    int mod = 1e9 + 7;

    int solve(int ind, int& n, bool isAb, int cL, vector<vector<vector<int>>>& dp) {
        if(ind == n) return 1;

        if(dp[ind][isAb][cL] != -1) return dp[ind][isAb][cL];

        int ans = solve(ind + 1, n, isAb, 0, dp) % mod;
        if(!isAb) ans = (ans + solve(ind + 1, n, true, 0, dp)) % mod;
        if(cL < 2) ans = (ans + solve(ind + 1, n, isAb, cL + 1, dp)) % mod;

        return dp[ind][isAb][cL] = ans;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, n, false, 0, dp);
    }
};
