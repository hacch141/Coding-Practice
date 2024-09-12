// 1684. Count the Number of Consistent Strings

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        vector<bool> f(26, false);
        for(auto ch : allowed) f[ch - 'a'] = true;
        for(auto s : words) {
            vector<bool> curr(26, false);
            for(auto ch : s) {
                curr[ch - 'a'] = true;
            }
            bool flag = true;
            for(int i = 0; i < 26; i++) {
                if(curr[i] == true && f[i] == false) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};
