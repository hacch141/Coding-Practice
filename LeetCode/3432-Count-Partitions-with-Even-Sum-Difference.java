// 3432. Count Partitions with Even Sum Difference

class Solution {
    public int countPartitions(int[] nums) {
        int n = nums.length;
        int l_sum = 0, r_sum = 0, ans = 0;
        for (int i : nums) r_sum += i;
        for (int i = 0; i < n - 1; i++) {
            l_sum += nums[i];
            r_sum -= nums[i];
            ans += ((l_sum - r_sum) % 2 == 0) ? 1 : 0;
        }
        return ans;
    }
}
