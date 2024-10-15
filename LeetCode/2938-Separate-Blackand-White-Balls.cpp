// 2938. Separate Black and White Balls

class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int n = s.length(), l = n - 1, r = n - 1;
        while(l >= 0) {
            if(s[l] == '1') {
                swap(s[l], s[r]);
                ans += r - l;
                r--;
            }
            l--;
        }
        return ans;
    }
};
