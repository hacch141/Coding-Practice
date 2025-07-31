// 3333. Find the Original Typed String II

// Memo
class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int ind, int m, vector<int>& f, int cnt, int k, vector<vector<int>>& dp) {
        if(ind == m) return cnt < k;
        if(dp[ind][cnt] != -1) return dp[ind][cnt];
        int res = 0;
        for(int i = 1; i <= f[ind]; i++) {
            if(cnt + i < k) {
                res = (res + solve(ind + 1, m, f, cnt + i, k, dp)) % MOD;
            }
            else {
                break;
            }
        }
        return dp[ind][cnt] = res;
    }

    int possibleStringCount(string word, int k) {
        int n = word.length();
        if(k > n) return 0;

        vector<int> f;
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(word[i] == word[i - 1]) {
                cnt++;
            }
            else {
                f.push_back(cnt);
                cnt = 1;
            }
        }
        f.push_back(cnt);

        long long total = 1;
        for(auto i : f) {
            total = (total * i) % MOD;
        }

        if(f.size() >= k) return total;
        
        int m = f.size();
        vector<vector<int>> dp(m, vector<int>(k + 1, -1));
        int lessThanK = solve(0, m, f, 0, k, dp);
        return (total - lessThanK + MOD) % MOD;
    }
};

// Tabulation
class Solution {
public:
    int MOD = 1e9 + 7;

    int possibleStringCount(string word, int k) {
        int n = word.length();
        if(k > n) return 0;

        vector<int> f;
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(word[i] == word[i - 1]) {
                cnt++;
            }
            else {
                f.push_back(cnt);
                cnt = 1;
            }
        }
        f.push_back(cnt);

        long long total = 1;
        for(auto i : f) {
            total = (total * i) % MOD;
        }

        if(f.size() >= k) return total;
        
        int m = f.size();
        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;

        for (int ind = 0; ind < m; ind++) {
            for (int cnt = 0; cnt <= k; cnt++) {
                if (dp[ind][cnt] == 0) continue;
                for (int i = 1; i <= f[ind]; i++) {
                    if (cnt + i < k) {
                        dp[ind + 1][cnt + i] = (dp[ind + 1][cnt + i] + dp[ind][cnt]) % MOD;
                    } else {
                        break;
                    }
                }
            }
        }

        int lessThanK = 0;
        for (int i = 0; i < k; i++) {
            lessThanK = (lessThanK + dp[m][i]) % MOD;
        }

        return (total - lessThanK + MOD) % MOD;
    }
};

// optimised tabulation
class Solution {
public:
    int MOD = 1e9 + 7;

    int possibleStringCount(string word, int k) {
        int n = word.length();
        if(k > n) return 0;

        vector<int> f;
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(word[i] == word[i - 1]) {
                cnt++;
            }
            else {
                f.push_back(cnt);
                cnt = 1;
            }
        }
        f.push_back(cnt);

        long long total = 1;
        for(auto i : f) {
            total = (total * i) % MOD;
        }

        if(f.size() >= k) return total;
        
        int m = f.size();
        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;

        for (int ind = 0; ind < m; ind++) {
            for (int cnt = 0; cnt <= k; cnt++) {
                if (dp[ind][cnt] == 0) continue;
                int l = cnt + 1, r = min(cnt + f[ind], k - 1);
                if(l >= k) continue;
                dp[ind + 1][l] = (dp[ind + 1][l] + dp[ind][cnt]) % MOD;
                dp[ind + 1][r + 1] = (dp[ind + 1][r + 1] - dp[ind][cnt] + MOD) % MOD;
            }
            for(int i = 1; i <= k; i++) {
                dp[ind + 1][i] = (dp[ind + 1][i] + dp[ind + 1][i - 1]) % MOD; 
            }
        }

        int lessThanK = 0;
        for (int i = 0; i < k; i++) {
            lessThanK = (lessThanK + dp[m][i]) % MOD;
        }

        return (total - lessThanK + MOD) % MOD;
    }
};
