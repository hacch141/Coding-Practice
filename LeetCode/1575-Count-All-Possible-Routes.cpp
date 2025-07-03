// 1575. Count All Possible Routes

class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int n, vector<int>& locations, int start, int finish, int fuel, vector<vector<int>>& dp) {
        if(fuel < 0) return 0;

        if(dp[start][fuel] != -1) return dp[start][fuel];

        int cnt = start == finish;
        for(int i = 0; i < n; i++) {
            if(i == start) continue;
            int fuel_burn = abs(locations[start] - locations[i]);
            cnt = (cnt + solve(n, locations, i, finish, fuel - fuel_burn, dp)) % MOD;
        }
        return dp[start][fuel] = cnt;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(201, -1));
        return solve(n, locations, start, finish, fuel, dp);
    }
};
