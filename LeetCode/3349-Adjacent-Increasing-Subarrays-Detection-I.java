// 3349. Adjacent Increasing Subarrays Detection I

class Solution {
    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n - k; i++) {
            boolean f = true;
            for (int j = 1; j < k; j++) {
                if (i + j + k >= n || nums.get(i + j) <= nums.get(i + j - 1) || nums.get(i + j + k) <= nums.get(i + j - 1 + k)) {
                    f = false;
                    break;
                }
            }
            if (f) return true;
        }
        return false;
    }
}
