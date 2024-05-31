// 260. Single Number III

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for(auto i : nums) xr ^= i;

        int bit = 0;
        while(((xr >> bit) & 1) != 1) bit++;

        vector<int> ans(2);
        for(auto i : nums) {
            if((i >> bit) & 1) ans[0] ^= i;
            else ans[1] ^= i;
        }

        return ans;
    }
};
