// 91. Decode Ways

class Solution {
public:
    int solve(int ind, int n, string& s, vector<int>& dp) {
        if(s[ind] == '0') return 0;
        if(ind >= n) return 1;

        if(dp[ind] != -1) return dp[ind];

        int cnt = 0;
        // for single digit
        cnt = (cnt + solve(ind + 1, n, s, dp));
        // for double digit
        if(ind + 1 < n && (s[ind] == '1' || (s[ind] == '2' && s[ind + 1] <= '6'))) {
            cnt = (cnt + solve(ind + 2, n, s, dp));
        }

        return dp[ind] = cnt;
    }

    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return solve(0, n, s, dp);
    }
};

// Iterative
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.length();
    
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            // single digit
            if(s[i] != '0') dp[i] += dp[i - 1];
            // double digit
            if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                if(i > 1)
                    dp[i] += dp[i - 2];
                else
                    dp[i] += 1;
            }
        }
        return dp[n - 1];
    }
};
