// 1416. Restore The Array

class Solution {
public:

    int mod = 1e9+7;

    int helper(string& s, int& k, int i, vector<int>& dp) {
        if(s[i]=='0') return 0;
        if(i==s.size()) return 1;

        if(dp[i] != -1) return dp[i];

        int n = s.length();
        int ans = 0;
        long num = 0;
        for(int j=i; j<n; j++) {
            num = num*10 + s[j]-'0';
            if(num>k) break;
            ans = (ans + helper(s,k,j+1,dp))%mod;
        }

        return dp[i] = ans;
    }

    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int> dp(n,-1);
        return helper(s,k,0,dp);
    }
};
