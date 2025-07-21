// 1957. Delete Characters to Make Fancy String

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string ans;
        for(int i = 0; i < n; i++) {
            if(i >= 2 && s[i] == s[i - 1] && s[i] == s[i - 2]) continue;
            ans += s[i];
        }
        return ans;
    }
};
