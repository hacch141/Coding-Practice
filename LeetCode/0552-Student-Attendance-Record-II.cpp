// 552. Student Attendance Record II

class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int ind, int n, int cnt_late, int cnt_abs, vector<vector<vector<int>>>& dp) {
        if(cnt_late >= 3 || cnt_abs >= 2) return 0;
        if(ind == n) return 1;

        if(dp[ind][cnt_late][cnt_abs] != -1) return dp[ind][cnt_late][cnt_abs];

        int A = solve(ind + 1, n, 0, cnt_abs + 1, dp);
        int L = solve(ind + 1, n, cnt_late + 1, cnt_abs, dp);
        int P = solve(ind + 1, n, 0, cnt_abs, dp);

        return dp[ind][cnt_late][cnt_abs] = (((A + L) % MOD) + P) % MOD;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));
        return solve(0, n, 0, 0, dp);
    }
};
