// 58. Length of Last Word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length(), ptr = n - 1, ans = 0;
        while(ptr >= 0 && s[ptr] == ' ') ptr--;
        while(ptr >= 0 && s[ptr] != ' ') {
            ans++;
            ptr--;
        }
        return ans;
    }
};
