// 1590. Make Sum Divisible by P

class Solution {
    public int minSubarray(int[] nums, int p) {
        int n = nums.length, ans = Integer.MAX_VALUE;
        long sum = 0, curr_sum = 0;
        for (int i : nums) sum += i;

        int rem = (int)(sum % p);
        if (rem == 0) return 0;

        Map<Integer,Integer> mp = new HashMap<>();
        mp.put(0, -1);
        for (int i = 0; i < n; i++) {
            curr_sum += nums[i];
            int curr_rem = (int)(curr_sum % p);
            int need = (int)((curr_rem - rem + p) % p);
            if (mp.containsKey(need)) {
                ans = Math.min(ans, i - mp.get(need));
            }
            mp.put(curr_rem, i);
        }
        return (ans != Integer.MAX_VALUE && ans != n) ? ans : -1;
    }
}
