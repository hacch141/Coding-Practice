// 713. Subarray Product Less Than K

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, n = nums.size(), l = 0;
        long long mul = 1;
        for(int r = 0; r < n; r++) {
            mul *= nums[r];
            while(l < r && mul >= k) {
                mul /= nums[l];
                l++;
            }
            if(mul < k) ans += r - l + 1;
        }
        return ans;
    }
};
