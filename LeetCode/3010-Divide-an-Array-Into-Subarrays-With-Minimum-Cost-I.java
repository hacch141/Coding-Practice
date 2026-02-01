// 3010. Divide an Array Into Subarrays With Minimum Cost I

class Solution {
    public int minimumCost(int[] nums) {
        int ans = nums[0];
        int mn1 = Integer.MAX_VALUE;
        int mn2 = Integer.MAX_VALUE;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] <= mn1) {
                mn2 = mn1;
                mn1 = nums[i];
            }
            else if (nums[i] < mn2) {
                mn2 = nums[i];
            }
        }
        return ans + mn1 + mn2;
    }
}
