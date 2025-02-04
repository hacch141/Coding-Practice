// 1800. Maximum Ascending Subarray Sum

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int mx = 0, n = nums.size(), curr = 0;
        for(int i = 0; i < n; i++) {
            if (i > 0 && nums[i] > nums[i - 1]) {
                curr += nums[i];
            }
            else {
                mx = max(mx, curr);
                curr = nums[i];
            }
        }
        mx = max(mx, curr);
        return mx;
    }
};
