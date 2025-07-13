// 91. Decode Ways

class Solution {
public:
    int solve(int ind, int n, string& s, vector<int>& dp) {
        if(s[ind] == '0') return 0;
        if(ind >= n) return 1;

        if(dp[ind] != -1) return dp[ind];

        int cnt = 0;
        // for single digit
        int curr = s[ind] - '0';
        cnt = (cnt + solve(ind + 1, n, s, dp));

        // for double digit
        if(ind + 1 < n) {
            curr = (10 * curr) + (s[ind + 1] - '0');
            if(curr <= 26) cnt = (cnt + solve(ind + 2, n, s, dp));
        }

        return dp[ind] = cnt;
    }

    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return solve(0, n, s, dp);
    }
};
