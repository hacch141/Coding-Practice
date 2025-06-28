// 87. Scramble String

class Solution {
public:
    bool solve(string s1, string s2, unordered_map<string, bool>& mp) {
        if(mp.count(s1 + "#" + s2)) return mp[s1 + "#" + s2];
        int n = s1.length();
        if(s1 == s2) return true;
        if(n == 1) return false;
        for(int i = 1; i < n; i++) {
            // swap(x, y) --> len(x1) == len(y2) && len(y1) == len(x2)
            string x1 = s1.substr(0, i);
            string y1 = s1.substr(i);
            string x2 = s2.substr(0, n - i);
            string y2 = s2.substr(n - i);
            bool swap = solve(x1, y2, mp) && solve(x2, y1, mp);

            // no_swap(x, y) --> len(x1) == len(x2) && len(y1) == len(y2)
            x2 = s2.substr(0, i);
            y2 = s2.substr(i);
            bool no_swap = solve(x1, x2, mp) && solve(y1, y2, mp);
            if(swap || no_swap) return mp[s1 + "#" + s2] = true;
        }
        return mp[s1 + "#" + s2] = false;
    }

    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> mp;
        return solve(s1, s2, mp);
    }
};
