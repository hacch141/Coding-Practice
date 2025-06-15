// 1143. Longest Common Subsequence

// Rec
class Solution {
public:
    int dp[1001][1001];

    int solve(int ind1, int ind2, int& n1, int& n2, string& text1, string& text2) {
        if(ind1 >= n1 || ind2 >= n2) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int curr = INT_MIN;
        if(text1[ind1] == text2[ind2]) {
            curr = max(curr, 1 + solve(ind1 + 1, ind2 + 1, n1, n2, text1, text2));
        }
        else {
            curr = max(curr, solve(ind1 + 1, ind2, n1, n2, text1, text2));
            curr = max(curr, solve(ind1, ind2 + 1, n1, n2, text1, text2));
        }

        return dp[ind1][ind2] = curr;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length(), n2 = text2.length();
        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < n2; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(0, 0, n1, n2, text1, text2);
    }
};

// DP
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<int> dp(n2+1,0), curr(n2+1,0);

        for(int i=1; i<=n1; i++) {
            for(int j=1; j<=n2; j++) {
                if(text1[i-1] == text2[j-1]) {
                    curr[j] = 1 + dp[j-1];
                } else {
                    curr[j] = max(dp[j],curr[j-1]);
                }
            }
            dp = curr;
        }
        return dp[n2];
    }
};
