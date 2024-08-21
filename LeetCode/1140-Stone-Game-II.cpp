// 1140. Stone Game II
class Solution {
public:

    int solve(int ind, int& n, int person, int m, vector<int>& piles, vector<vector<vector<int>>>& dp) {
        if(ind >= n) return 0;
        if(dp[ind][m][person] != -1) return dp[ind][m][person];
        int sum = 0, ans = (person == 1 ? 0 : 1e9);
        for(int i = 0; i < 2 * m; i++) {
            if(i + ind >= n) break;
            sum += piles[i + ind];
            if(person == 1) {
                ans = max(ans, sum + solve(ind + i + 1, n, 0, max(m, i + 1), piles, dp));
            }
            else {
                ans = min(ans, solve(ind + i + 1, n, 1, max(m, i + 1), piles, dp));
            }
        }
        return dp[ind][m][person] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return solve(0, n, 1, 1, piles, dp);
    }
};
