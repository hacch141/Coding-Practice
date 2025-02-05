// 1790. Check if One String Swap Can Make Strings Equal

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt_not_match = 0, n = s1.length();
        for(int i = 0; i < n; i++) {
            cnt_not_match += s1[i] != s2[i];
        }
        if(cnt_not_match == 0) {
            return true;
        }
        else if(cnt_not_match == 2) {
            int l = -1, r = -1;
            for(int i = 0; i < n; i++) {
                if (s1[i] != s2[i]) {
                    if(l == -1) l = i;
                    r = i;       
                }
            }
            return s1[l] == s2[r] && s1[r] == s2[l];
        }
        return false;
    }
};
