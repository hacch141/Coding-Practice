// 1750. Minimum Length of String After Deleting Similar Ends

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length(), l = 0, r = n - 1;
        while(l < r) {
            char ch = s[l];
            if(s[l] == s[r]) {
                while(l <= r && s[l] == ch) l++;
                while(l <= r && s[r] == ch) r--;
            }
            else {
                break;
            }
        }
        return r - l + 1;
    }
};
