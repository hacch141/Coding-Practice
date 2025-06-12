// 3423. Maximum Difference Between Adjacent Elements in a Circular Array

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size(), ans = abs(nums[0] - nums[n - 1]);
        for(int i = 0; i < nums.size() - 1; i++) {
            ans = max(ans, abs(nums[i] - nums[i + 1]));
        }
        return ans;
    }
};
