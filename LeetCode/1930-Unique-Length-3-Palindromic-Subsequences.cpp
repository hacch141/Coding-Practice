// 1930. Unique Length-3 Palindromic Subsequences

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> lstInd(26, -1);
        int n = s.length(), ans = 0;
        for(int i = 0; i < n; i++) lstInd[s[i] - 'a'] = i;
        set<char> vis;
        for(int i = 0; i < n; i++) {
            if(vis.count(s[i])) continue;
            vis.insert(s[i]);
            int start = i + 1, end = lstInd[s[i] - 'a'];
            set<char> st;
            for(int j = start; j < end; j++) {
                st.insert(s[j]);
            }
            ans += st.size();
        }
        return ans;
    }
};
