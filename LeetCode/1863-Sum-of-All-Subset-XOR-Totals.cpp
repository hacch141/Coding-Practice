// 1863. Sum of All Subset XOR Totals

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < (1 << n); i++) {
            int xr = 0;
            for(int bit = 0; bit <= 12; bit++) {
                if((i >> bit) & 1) {
                    xr ^= nums[bit];
                }
            }
            ans += xr;
        }
        return ans;
    }
};
