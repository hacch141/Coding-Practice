// 198. House Robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0, n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int prev2 = nums[0], prev = max(nums[1], nums[0]);
        for(int i=2; i<n; i++) {
            int curr = max(nums[i] + prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
