// 2901. Longest Unequal Adjacent Groups Subsequence II

class Solution {
public:
    bool ok(string& s1, string& s2) {
        int n1 = s1.length(), n2 = s2.length(), cnt = 0;
        if(n1 != n2) return false;
        for(int i = 0; i < n1; i++) cnt += s1[i] != s2[i];
        return cnt == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size(), mx = 1, ind = 0;
        vector<int> prev(n), dp(n, 1);
        for(int i = 0; i < n; i++) prev[i] = i;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(groups[i] != groups[j] && ok(words[i], words[j]) && (1 + dp[i] > dp[j])) {
                    dp[j] = 1 + dp[i];
                    prev[j] = i;
                    if(dp[j] > mx) {
                        mx = dp[j];
                        ind = j;
                    }
                }
            }
        }

        vector<string> ans;
        while(prev[ind] != ind) {
            ans.push_back(words[ind]);
            ind = prev[ind];
        }
        ans.push_back(words[ind]);
        reverse(ans.begin(),ans.end());

        return ans;
    }
};
