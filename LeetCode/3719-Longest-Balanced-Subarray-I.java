// 3719. Longest Balanced Subarray I

class Solution {
    public int longestBalanced(int[] nums) {
        int n = nums.length;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            Set<Integer> stOdd = new HashSet<>();
            Set<Integer> stEven = new HashSet<>();
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    stEven.add(nums[j]);
                }
                else {
                    stOdd.add(nums[j]);
                }
                if (stOdd.size() == stEven.size()) {
                    ans = Math.max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
}
