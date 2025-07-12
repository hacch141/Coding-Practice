// 97. Interleaving String

class Solution {
public:
    bool solve(int ind1, int ind2, int ind3, int n1, int n2, int n3, string& s1, string& s2, string& s3, vector<vector<vector<int>>>& dp) {
        if(ind1 == n1 && ind2 == n2 && ind3 == n3) return true;

        if(dp[ind1][ind2][ind3] != -1) return dp[ind1][ind2][ind3];
        bool f = false;
        if(ind1 < n1 && s1[ind1] == s3[ind3]) {
            f |= solve(ind1 + 1, ind2, ind3 + 1, n1, n2, n3, s1, s2, s3, dp);
        }
        if(ind2 < n2 && s2[ind2] == s3[ind3]) {
            f |= solve(ind1, ind2 + 1, ind3 + 1, n1, n2, n3, s1, s2, s3, dp);
        }

        return dp[ind1][ind2][ind3] = f;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1)));
        return solve(0, 0, 0, n1, n2, n3, s1, s2, s3, dp);
    }
};
