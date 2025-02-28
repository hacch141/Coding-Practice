// 1092. Shortest Common Supersequence 

class Solution {
public:

    string get_lcs(string& str1, string& str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        string lcs;
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                lcs = str1[i - 1] + lcs;
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        
        return lcs;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = get_lcs(str1, str2);
        int ind_lcs = 0, ind_str1 = 0, ind_str2 = 0;
        string ans;

        while(ind_lcs < lcs.length()) {
            while(str1[ind_str1] != lcs[ind_lcs]) {
                ans += str1[ind_str1];
                ind_str1++;
            }
            while(str2[ind_str2] != lcs[ind_lcs]) {
                ans += str2[ind_str2];
                ind_str2++;
            }
            ans += lcs[ind_lcs];
            ind_lcs++;
            ind_str1++;
            ind_str2++;
        }

        while(ind_str1 < str1.length()) {
            ans += str1[ind_str1];
            ind_str1++;
        }

        while(ind_str2 < str2.length()) {
            ans += str2[ind_str2];
            ind_str2++;
        }

        return ans;
    }
};
