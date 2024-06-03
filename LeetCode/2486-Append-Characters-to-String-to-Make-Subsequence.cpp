// 2486. Append Characters to String to Make Subsequence

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length(), m = t.length(), p1 = 0, p2 = 0;
        while(p1 < n && p2 < m) {
            if(s[p1] == t[p2]) p2++;
            p1++;
        }
        return m - p2;
    }
};
