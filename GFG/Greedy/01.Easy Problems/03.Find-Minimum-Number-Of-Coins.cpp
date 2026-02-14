// Find Minimum Number Of Coins

class Solution {
    int INF = (int)1e9;
    int[][] dp;

    public int solve(int ind, int n, int[] coins, int amount) {
        if (ind == n) {
            return amount == 0 ? 0 : INF;
        }

        if (dp[ind][amount] != -1) return dp[ind][amount];

        int take = INF;
        if (amount - coins[ind] >= 0)
            take = 1 + solve(ind, n, coins, amount - coins[ind]);

        int nottake = solve(ind + 1, n, coins, amount);

        return dp[ind][amount] = Math.min(take, nottake);
    }

    public int coinChange(int[] coins, int amount) {

        int n = coins.length;
        dp = new int[n][amount + 1];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }

        int ans = solve(0, n, coins, amount);

        return ans != INF ? ans : -1;
    }
}

// =============================================================================

// only possible with real currency(IND, etc)
// where you have to take as Max as possible greedily
vector<int> MinimumCoins(int n)
{
    // Write your code here
    vector<int> coins = {1,2,5,10,20,50,100,500,1000};
    vector<int> ans;
    for(int i=8; i>=0; i--) {
        while(coins[i] <= n) {
            n -= coins[i];
            ans.push_back(coins[i]);
        }
    }

    return ans;
}

// T : O(Number of coins)
// S : O(1)
