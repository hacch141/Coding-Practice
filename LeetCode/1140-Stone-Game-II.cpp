// 1140. Stone Game II

class Solution {
public:
    int solve(int ind, int M, bool alice, int n, vector<int>& piles, vector<vector<vector<int>>>& dp) {
        if(ind >= n) return 0;

        if(dp[ind][M][alice] != -1) return dp[ind][M][alice];

        int curr_stones = 0, ans = alice ? 0 : 1e9;
        for(int i = 0; i < 2 * M; i++) {
            if(ind + i >= n) break;
            curr_stones += piles[ind + i];
            if(alice) {
                // take max bcz alice play optimally
                ans = max(ans, curr_stones + solve(ind + i + 1, max(i + 1, M), !alice, n, piles, dp));
            }
            else {
                // take min bcz bob play optimally
                ans = min(ans, solve(ind + i + 1, max(i + 1, M), !alice, n, piles, dp));
            }
        }
        return dp[ind][M][alice] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>((2 * n) + 1, vector<int>(2, -1)));
        return solve(0, 1, true, n, piles, dp);
    }
};
