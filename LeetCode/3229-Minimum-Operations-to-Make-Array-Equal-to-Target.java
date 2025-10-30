// 3229. Minimum Operations to Make Array Equal to Target

class Solution {
    public long minimumOperations(int[] nums, int[] target) {
        long ans = 0, curr = 0, prev = 0;
        for (int i = 0; i < nums.length; i++) {
            curr = target[i] - nums[i];
            if ((curr < 0 && prev > 0) || (curr > 0 && prev < 0)) {
                ans += Math.abs(curr);
            }
            else if (Math.abs(curr) > Math.abs(prev)) {
                ans += Math.abs(curr - prev);
            }
            prev = curr;
        }
        return ans;
    }
}
