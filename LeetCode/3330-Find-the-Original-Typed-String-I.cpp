// 3330. Find the Original Typed String I

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length(), l = 0, ans = 0;
        for(int r = 0; r < n; r++) {
            if(word[r] != word[l]) {
                ans += r - l - 1;
                l = r;
            }
        }
        ans += n - l - 1;
        return ans + 1;
    }
};
