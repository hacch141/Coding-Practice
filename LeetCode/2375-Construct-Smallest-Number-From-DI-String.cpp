// 2375. Construct Smallest Number From DI String

class Solution {
public:
    void rec(int ind, int& n, char prev, string& curr, vector<bool>& vis, string& pattern, string& ans) {
        if(ind == n) {
            ans = min(ans, curr);
            return;
        }
        if(pattern[ind] == 'I') {
            prev++;
            for(char ch = prev; ch <= '9'; ch++) {
                if(vis[ch - '0']) continue;
                vis[ch - '0'] = true;
                curr += ch;
                rec(ind + 1, n, ch, curr, vis, pattern, ans);
                vis[ch - '0'] = false;
                curr.pop_back();
            }
        }
        else {
            prev--;
            for(char ch = prev; ch > '0'; ch--) {
                if(vis[ch - '0']) continue;
                vis[ch - '0'] = true;
                curr += ch;
                rec(ind + 1, n, ch, curr, vis, pattern, ans);
                vis[ch - '0'] = false;
                curr.pop_back();
            }
        }
    }

    string smallestNumber(string pattern) {
        int n = pattern.length();
        vector<bool> vis(10, false);
        string ans(10, '9');
        string curr = "";

        for(char ch = '1'; ch <= '9'; ch++) {
            curr += ch;
            vis[ch - '0'] = true;
            rec(0, n, ch, curr, vis, pattern, ans);
            vis[ch - '0'] = false;
            curr.pop_back();
        }
        return ans;
    }
};
