// 647. Palindromic Substrings
class Solution {
public:
    int check(int l, int r, string& s) {
        int cnt = 0;
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int n = s.length(), ans = 0;
        for(int i = 0; i < n; i++) {
            ans += check(i, i, s);
            ans += check(i, i + 1, s);
        }
        return ans;
    }
};

// Rec
class Solution {
public:
    bool solve(int i, int j, int n, string& s, vector<vector<int>>& dp) {
        if(i >= j) return true;
        if(s[i] != s[j]) return false;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = solve(i + 1, j - 1, n, s, dp);
    }

    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                ans += solve(i, j, n, s, dp);
            }
        }
        return ans;
    }
};

// Bottom Up
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int r = 0; r < n; r++) {
            for(int l = 0; l <= r; l++) {
                if(l == r) dp[l][r] = true;
                else if(l + 1 == r) dp[l][r] = (s[l] == s[r]);
                else dp[l][r] = (s[l] == s[r] && dp[l + 1][r - 1]);
                ans += dp[l][r];
            }
        }
        return ans;
    }
};
