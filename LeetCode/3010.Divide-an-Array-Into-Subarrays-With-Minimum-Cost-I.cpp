// 3010. Divide an Array Into Subarrays With Minimum Cost I

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0], mn1 = 51, mn2 = 51;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] <= mn1) {
                mn2 = mn1;
                mn1 = nums[i];
            }
            else if(nums[i] <= mn2) {
                mn2 = nums[i];
            }
        }
        return ans + mn1 + mn2;
    }
};
