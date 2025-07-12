// 403. Frog Jump

class Solution {
public:
    bool solve(int ind, int n, int k, vector<int>& stones, unordered_map<int,int>& mp, vector<vector<int>>& dp) {
        if(ind == n - 1) return true;

        if(dp[ind][k] != -1) return dp[ind][k];

        bool f = false;
        // k > 1 so we can go forward and don't stuck at same position infinite loop
        if(k > 1 && mp.count(stones[ind] + k - 1)) {
            f |= solve(mp[stones[ind] + k - 1], n, k - 1, stones, mp, dp);
        }
        if(mp.count(stones[ind] + k)) {
            f |= solve(mp[stones[ind] + k], n, k, stones, mp, dp);
        }
        if(mp.count(stones[ind] + k + 1)) {
            f |= solve(mp[stones[ind] + k + 1], n, k + 1, stones, mp, dp);
        }
        return dp[ind][k] = f;
    }

    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        int n = stones.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) mp[stones[i]] = i;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(1, n, 1, stones, mp, dp);
    }
};
