// 3634. Minimum Removals to Balance Array

class Solution {
    public int minRemoval(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);

        int l = 0;
        int ans = Integer.MAX_VALUE;

        for (int r = 0; r < n; r++) {
            while (l <= r && 1L * k * nums[l] < 1L * nums[r]) {
                l++;
            }
            ans = Math.min(ans, n - (r - l + 1));
        }
    
        return ans;
    }
}
