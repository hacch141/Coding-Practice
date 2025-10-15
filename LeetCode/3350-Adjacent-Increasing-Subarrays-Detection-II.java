// 3350. Adjacent Increasing Subarrays Detection II

class Solution {
    public int maxIncreasingSubarrays(List<Integer> nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int prev = -1, ans = 0;
        while (i < n) {
            j = i + 1;
            while (j < n && nums.get(j) > nums.get(j - 1)) j++;
            int curr = j - i;
            ans = Math.max(ans, curr / 2);
            if (prev != -1) ans = Math.max(ans, Math.min(prev, curr));
            prev = curr;
            i = j;
        }
        return ans;
    }
}
