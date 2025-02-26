// 1749. Maximum Absolute Sum of Any Subarray

class Solution {
public:
    int kadanes(vector<int>& nums) {
        int n = nums.size(), mx = 0, curr_sum = 0;
        for(int i = 0; i < n; i++) {
            curr_sum += nums[i];
            if(curr_sum < 0) curr_sum = 0;
            mx = max(mx, curr_sum);
        }
        return mx;
    }
    
    int maxAbsoluteSum(vector<int>& nums) {
        int mx = kadanes(nums);
        for(auto &i : nums) i = -i;
        mx = max(mx, kadanes(nums));
        return mx;
    }
};
