// 1004. Max Consecutive Ones III

class Solution {
    public int longestOnes(int[] nums, int k) {
        int n = nums.length;
        int l = 0, r = 0, ans = 0;
        int cnt = 0;
        while (r < n) {
            cnt += (nums[r] == 0 ? 1 : 0);
            while (cnt > k) {
                cnt -= (nums[l] == 0 ? 1 : 0);
                l++;
            }
            ans = Math.max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
}
