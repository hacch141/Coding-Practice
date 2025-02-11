// 1910. Remove All Occurrences of a Substring

class Solution {
public:
    bool ok(int ind, string s, string part) {
        int n = s.length();
        if(ind + part.length() > n) return false;
        for(int i = 0; i < part.length(); i++) {
            if(s[ind + i] != part[i]) return false;
        }
        return true;
    }

    string removeOccurrences(string s, string part) {
        while(1) {
            int n = s.length();
            bool f = true;
            for(int i = 0; i < n; i++) {
                if(ok(i, s, part)) {
                    s = s.substr(0, i) + s.substr(i + part.length());
                    f = false;
                    break;
                }
            }
            if(f) break;
        }
        return s;
    }
};
