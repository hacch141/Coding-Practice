// 3392. Count Subarrays of Length Three With a Condition

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 1; i < n - 1; i++) {
            ans += 2 * (nums[i - 1] + nums[i + 1]) == nums[i];
        }
        return ans;
    }
};
