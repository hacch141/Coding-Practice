// 2044. Count Number of Maximum Bitwise-OR Subsets

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), mx = 0, ans = 0;
        for(auto i : nums) mx |= i;
        for(int i = 0; i < (1 << n); i++) {
            int _or = 0;
            for(int j = 0; j < 32; j++) {
                if(1 & (i >> j)) {
                    _or |= nums[j];
                }
            }
            ans += mx == _or;
        }
        return ans;
    }
};
