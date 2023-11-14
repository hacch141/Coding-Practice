// 1930. Unique Length-3 Palindromic Subsequences

class Solution {
public:

    int helper(string s, int start, int end) {
        vector<int> vis(26,0);
        int cnt = 0;
        
        for(int i=start+1; i<=end-1; i++) {
            if(!vis[s[i]-'a']) {
                cnt++;
                vis[s[i]-'a'] = 1;
            }
        }

        return cnt;
    }

    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<vector<int>> map(26, vector<int>(2,-1));

        for(int i=0; i<n; i++) {
            int ind = s[i] - 'a';
            if(map[ind][0] == -1) {
                map[ind][0] = i;
                map[ind][1] = i;
            }
            else {
                map[ind][1] = i;
            }
        }

        int ans = 0;
        for(int i=0; i<26; i++) {
            int start = map[i][0];
            int end = map[i][1];
            if (start != -1 && end != -1 && start < end) {
                ans += helper(s, start, end);
            }
        }

        return ans;
    }
};
