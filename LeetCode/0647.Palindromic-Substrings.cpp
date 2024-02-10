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



class Solution {
public:

    int countSubstrings(string s) {
        int n = s.length(), ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, -1));
        for(int L = 1; L <= n; L++) {
            for(int l = 0; l + L - 1 < n; l++) {
                int r = l + L - 1;
                if(l == r) {
                    dp[l][r] = true;
                }
                else if(l + 1 == r) {
                    dp[l][r] = s[l] == s[r];
                }
                else {
                    dp[l][r] = (s[l] == s[r] && dp[l + 1][r - 1]);
                }
                ans += dp[l][r];
            }
        }
        return ans;
    }
};




class Solution {
public:

    vector<vector<int>> dp;

    Solution() {
        dp.resize(1001, vector<int>(1001, -1));
    }

    bool ok(int l, int r, string& s) {
        if(l >= r) return true;
        if(dp[l][r] != -1) return dp[l][r];
        if(s[l] != s[r]) return dp[l][r] = false;
        return dp[l][r] = ok(l + 1, r - 1, s);
    }

    int countSubstrings(string s) {
        int n = s.length(), ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(ok(i, j, s)) ans++;
            }
        }

        return ans;
    }
};
