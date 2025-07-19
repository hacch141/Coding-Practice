// 650. 2 Keys Keyboard

// rec
class Solution {
public:
    int solve(int ind, int n, int last_copy, vector<vector<int>>& dp) {
        if(ind == n) return 0;
        if(ind > n) return 1e9;

        if(dp[ind][last_copy] != -1) return dp[ind][last_copy];

        int copy = INT_MAX;
        if(ind != last_copy) copy = 1 + solve(ind, n, ind, dp);
        int paste = INT_MAX;
        if(last_copy > 0) paste = 1 + solve(ind + last_copy, n, last_copy, dp);

        return dp[ind][last_copy] = min(copy, paste);
    }

    int minSteps(int n) {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(1, n, 0, dp);
    }
};

// Math
class Solution {
public:
    int minSteps(int n) {
        map<int,int> mp;
        for(int i = 2; i <= n; i++) {
            while(n % i == 0) {
                mp[i]++;
                n /= i;
            }
        }
        int ans = 0;
        for(auto it : mp) ans += it.first * it.second;
        return ans;
    }
};
