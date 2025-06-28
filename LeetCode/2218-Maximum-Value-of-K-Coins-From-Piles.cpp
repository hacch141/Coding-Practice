// 2218. Maximum Value of K Coins From Piles

class Solution {
public:
    int solve(int ind, int n, vector<vector<int>>& piles, int k, vector<vector<int>>& dp) {
        if(ind == n || k == 0) return 0;
        if(dp[ind][k] != -1) return dp[ind][k];

        int m = piles[ind].size();
        int not_take = solve(ind + 1, n, piles, k, dp);
        int take = 0, sum = 0;
        for(int i = 0; i < min(m, k); i++) {
            sum += piles[ind][i];
            take = max(take, sum + solve(ind + 1, n, piles, k - i - 1, dp));
        }
        
        return dp[ind][k] = max(take, not_take);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(0, n, piles, k, dp);
    }
};
