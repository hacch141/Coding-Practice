// 3258. Count Substrings That Satisfy K-Constraint I

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length(), l = 0, c1 = 0, c0 = 0, ans = 0;
        for(int r = 0; r < n; r++) {
            if(s[r] == '0') c0++;
            else c1++;
            while(c1 > k && c0 > k) {
                if(s[l] == '0') c0--;
                else c1--;
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};
