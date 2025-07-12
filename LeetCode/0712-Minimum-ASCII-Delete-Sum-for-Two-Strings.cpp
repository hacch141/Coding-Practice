// 712. Minimum ASCII Delete Sum for Two Strings

class Solution {
public:
    int solve(int ind1, int ind2, int n1, int n2, string& s1, string& s2, vector<vector<int>>& dp) {
        if(ind1 >= n1 && ind2 >= n2) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int take = INT_MAX, nottake = INT_MAX;
        if(ind1 < n1 && ind2 < n2 && s1[ind1] == s2[ind2]) {
            nottake = solve(ind1 + 1, ind2 + 1, n1, n2, s1, s2, dp);
        }
        else {
            if(ind1 < n1) take = min(take, s1[ind1] + solve(ind1 + 1, ind2, n1, n2, s1, s2, dp));
            if(ind2 < n2) take = min(take, s2[ind2] + solve(ind1, ind2 + 1, n1, n2, s1, s2, dp));
        }
        return dp[ind1][ind2] = min(take, nottake);
    }

    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return solve(0, 0, n1, n2, s1, s2, dp); 
    }
};
