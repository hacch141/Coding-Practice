// 139. Word Break

class Solution {
public:
    bool solve(int ind, int n, string& s, unordered_set<string>& st, vector<int>& dp) {
        if(ind == n) return true;

        if(dp[ind] != -1) return dp[ind];

        string curr = "";
        for(int i = ind; i < n; i++) {
            curr += s[i];
            if(st.count(curr) && solve(i + 1, n, s, st, dp)) return dp[ind] = true;
        }
        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st;
        for(auto s : wordDict) st.insert(s);
        vector<int> dp(n, -1);
        return solve(0, n, s, st, dp);
    }
};
