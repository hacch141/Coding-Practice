// 2707. Extra Characters in a String

class Solution {
public:
    int solve(int ind, int& n, string& s, set<string>& st, vector<int>& dp) {
        if(ind == n) return 0;
        if(dp[ind] != -1) return dp[ind];
        string curr = "";
        int ans = INT_MAX;
        for(int i = ind; i < n; i++) {
            curr.push_back(s[i]);
            if(st.count(curr)) {
                ans = min(ans, solve(i + 1, n, s, st, dp));
            }
            else {
                ans = min(ans, i - ind + 1 + solve(i + 1, n, s, st, dp));
            }
        }
        return dp[ind] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        set<string> st;
        for(auto i : dictionary) st.insert(i);
        vector<int> dp(n, -1);
        return solve(0, n, s, st, dp);
    }
};
