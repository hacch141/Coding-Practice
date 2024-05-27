// 1608. Special Array With X Elements Greater Than or Equal X

class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int> pref(1002, 0);
        for(auto i : nums) pref[i + 1]++;
        for(int i = 1; i < 1002; i++) pref[i] += pref[i - 1];
        int l = 0, h = 100, ans = 0;
        while(l <= h) {
            int m = (h - l) / 2 + l;
            if(pref[1001] - pref[m] >= m) {
                if(pref[1001] - pref[m] == m)ans = m;
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }
        return ans != 0 ? ans : -1;
    }
};
