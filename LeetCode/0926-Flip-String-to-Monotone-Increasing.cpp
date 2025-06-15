// 926. Flip String to Monotone Increasing

// Rec
class Solution {
public:
    int dp[100001][2];

    int solve(int ind, int& n, int prev, string& s) {
        if(ind >= n) return 0;

        if(dp[ind][prev] != -1) return dp[ind][prev];

        int flip = INT_MAX, noflip = INT_MAX;

        if(s[ind] == '0') {
            if(prev == 1) {
                flip = 1 + solve(ind + 1, n, 1, s);
            }
            else {
                flip = 1 + solve(ind + 1, n, 1, s);
                noflip = solve(ind + 1, n, 0, s);
            }
        }
        else {
            if(prev == 1) {
                noflip = solve(ind + 1, n, 1, s);
            }
            else {
                flip = 1 + solve(ind + 1, n, 0, s);
                noflip = solve(ind + 1, n, 1, s);
            }
        }

        return dp[ind][prev] = min(flip, noflip);
    }

    int minFlipsMonoIncr(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, 0, s);
    }
};

// Prefix
class Solution {
public:
    int get_cnt(int l, int r, vector<int>& f) {
        if(l > r) return 0;
        int cnt = f[r];
        if(l > 0) cnt -= f[l - 1];
        return cnt;
    }

    int minFlipsMonoIncr(string s) {
        int n = s.length();

        vector<int> f1(n, 0), f0(n, 0);
        for(int i = 0; i < n; i++) {
            f0[i] += (s[i] == '0');
            f1[i] += (s[i] == '1');
        }

        for(int i = 1; i < n; i++) {
            f0[i] += f0[i - 1];
            f1[i] += f1[i - 1];
        }

        int ans = n;
        for(int i = 0; i <= n; i++) {
            int curr = get_cnt(0, i - 1, f1);
            curr += get_cnt(i, n - 1, f0);
            ans = min(ans, curr);
        }

        return ans;
    }
};

// 
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();

        int c1 = 0, c0 = 0;
        for(auto &ch : s) c0 += ch == '0';

        int ans = c0;
        for(auto &ch : s) {
            c0 -= ch == '0';
            c1 += ch == '1';
            ans = min(ans, c0 + c1);
        }

        return ans;
    }
};
