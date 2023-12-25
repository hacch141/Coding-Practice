// 91. Decode Ways

class Solution {
public:

    int solve(int ind, int& n, string& s, vector<int>& dp) {
        if(ind == s.length()) return 1;
        if(s[ind] == '0') return 0;

        if(dp[ind] != -1) return dp[ind];
        
        int one = solve(ind+1, n, s, dp);
        int two = 0;
        if(ind < s.length() - 1 && s.substr(ind,2) <= "26") two = solve(ind+2, n, s, dp);

        return dp[ind] = one + two;
    }

    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n,-1);
        return solve(0, n, s, dp);
    }
};
