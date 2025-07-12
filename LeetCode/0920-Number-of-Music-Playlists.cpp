// 920. Number of Music Playlists

class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int cnt, int unq, int n, int goal, int k, vector<vector<int>>& dp) {
        if(cnt == goal) return unq == n;

        if(dp[cnt][unq] != -1) return dp[cnt][unq];

        long long ans = 0;
        // play new song
        if(unq < n) {
            ans = (ans + 1LL * (n - unq) * solve(cnt + 1, unq + 1, n, goal, k, dp)) % MOD;
        }

        // repeat song
        if(unq > k) {
            ans = (ans + 1LL * (unq - k) * solve(cnt + 1, unq, n, goal, k, dp)) % MOD;
        }

        return dp[cnt][unq] = ans;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(goal, vector<int>(n + 1, -1));
        return solve(0, 0, n, goal, k, dp);
    }
};
