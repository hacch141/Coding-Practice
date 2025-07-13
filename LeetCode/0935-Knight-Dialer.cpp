// 935. Knight Dialer

class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int u, int n, vector<vector<int>>& adj, vector<vector<int>>& dp) {
        if(n == 0) return 1;

        if(dp[n][u] != -1) return dp[n][u];

        int cnt = 0;
        for(auto v : adj[u]) {
            cnt = (cnt + solve(v, n - 1, adj, dp)) % MOD;
        }
        return dp[n][u] = cnt;
    }

    int knightDialer(int n) {
        vector<vector<int>> adj(10);
        adj[0] = {4, 6};
        adj[1] = {6, 8};
        adj[2] = {7, 9};
        adj[3] = {4, 8};
        adj[4] = {0, 3, 9};
        adj[5] = {};
        adj[6] = {0, 1, 7};
        adj[7] = {2, 6};
        adj[8] = {1, 3};
        adj[9] = {2, 4};

        vector<vector<int>> dp(n, vector<int>(10, -1));

        int ans = 0;
        for(int i = 0; i < 10; i++) {
            ans = (ans + solve(i, n - 1, adj, dp)) % MOD;
        }
        return ans;
    }
};

// Iterative
class Solution {
public:
    int MOD = 1e9 + 7;

    int knightDialer(int n) {
        vector<vector<int>> adj(10);
        adj[0] = {4, 6};
        adj[1] = {6, 8};
        adj[2] = {7, 9};
        adj[3] = {4, 8};
        adj[4] = {0, 3, 9};
        adj[5] = {};
        adj[6] = {0, 1, 7};
        adj[7] = {2, 6};
        adj[8] = {1, 3};
        adj[9] = {2, 4};

        vector<vector<int>> dp(n, vector<int>(10, 0));

        // base case for n = 1 return 1
        for(int i = 0; i < 10; i++) dp[0][i] = 1;

        int ans = 0;
        for(int i = 1; i < n; i++) {
            for(int v = 0; v < 10; v++) {
                for(auto u : adj[v]) {
                    dp[i][v] = (dp[i][v] + dp[i - 1][u]) % MOD;
                }
            }
        }

        for(int i = 0; i < 10; i++) {
            ans = (ans + dp[n - 1][i]) % MOD;
        }
        return ans;
    }
};
