// 2997. Minimum Number of Operations to Make Array XOR Equal to K

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int xr = 0, ans = 0;
        for(auto i : nums) xr ^= i;
        while(xr || k) {
            if((xr & 1) != (k & 1)) ans++;
            xr >>= 1;
            k >>= 1;
        }
        return ans;
    }
};
