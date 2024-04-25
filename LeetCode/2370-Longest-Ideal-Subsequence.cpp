// 2370. Longest Ideal Subsequence

class Solution {
public:

    int solve(int ind, int& n, string& s, int& k, char prev, vector<vector<int>>& dp) {
        if(ind == n) return 0;

        if(dp[ind][prev - 'a'] != -1) return dp[ind][prev - 'a'];

        int nottake = solve(ind + 1, n, s,  k, prev, dp);
        int take = 0;
        if(prev == '{' || abs(prev - s[ind]) <= k) {
            take = 1 + solve(ind + 1, n, s, k, s[ind], dp);
        }
        return dp[ind][prev - 'a'] = max(take, nottake);
    }

    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(27, -1));
        return solve(0, n, s, k, '{', dp);
    }
};



class Solution {
public:

    int longestIdealString(string s, int k) {
        int n = s.length(), ans = 0;
        vector<int> dp(26, 0);
        for(int i = 0; i < n; i++) {
            int mx = dp[s[i] - 'a'];
            for(char prev = 'a' ; prev <= 'z'; prev++) {
                if(abs(s[i] - prev) <= k) {
                    mx = max(mx, 1 + dp[prev - 'a']);
                }
            }
            dp[s[i] - 'a'] = mx;
            ans = max(ans, mx);
        }
        return ans;
    }
};
