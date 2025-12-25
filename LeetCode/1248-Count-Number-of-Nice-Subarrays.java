// 1248. Count Number of Nice Subarrays

class Solution {
    public int getCnt(int l, int r, int[] nums) {
        int n = nums.length;
        int cl = 0, cr = 0;
        while (l >= 0 && nums[l--] % 2 == 0) cl++;
        while (r < n && nums[r++] % 2 == 0) cr++;
        return (1 + cl) * (1 + cr);
    }

    public int numberOfSubarrays(int[] nums, int k) {
        int n = nums.length;
        int l = 0, r = 0, ans = 0, cntOdd = 0;
        while (r < n) {
            if (nums[r] % 2 == 1) cntOdd++;
            while (l < r && nums[l] % 2 == 0) l++;
            if (cntOdd == k) {
                ans += getCnt(l - 1, r + 1, nums);
                cntOdd--;
                l++;
            }
            r++;
        }
        return ans;
    }
}
