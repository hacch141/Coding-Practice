// 930. Binary Subarrays With Sum

class Solution {
    public int getCnt(int l, int r, int[] nums) {
        int n = nums.length;
        int cl = 0, cr = 0;
        while (l >= 0 && nums[l--] == 0) cl++;
        while (r < n && nums[r++] == 0) cr++;
        return (1 + cl) * (1 + cr);
    }

    public int numSubarraysWithSum(int[] nums, int goal) {
        int n = nums.length;
        int l = 0, r = 0, ans = 0, sum = 0;
        if (goal == 0) {
            int cnt = 0, c0 = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) c0++;
                else {
                    ans += (c0 * (c0 + 1)) / 2;
                    c0 = 0;
                } 
            }
            ans += (c0 * (c0 + 1)) / 2;
            return ans;
        }
        while (r < n) {
            sum += nums[r];
            while (l < r && nums[l] == 0) l++;
            if (sum == goal) {
                ans += getCnt(l - 1, r + 1, nums);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return ans;
    }
}
