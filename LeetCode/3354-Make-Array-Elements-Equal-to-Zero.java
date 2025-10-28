// 3354. Make Array Elements Equal to Zero

class Solution {
    public int countValidSelections(int[] nums) {
        int n = nums.length;
        int[] pref = new int[n];
        for (int i = 0; i < n; i++) {
            pref[i] = nums[i];
            if (i > 0) pref[i] += pref[i - 1];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) continue;
            int l = pref[i];
            int r = pref[n - 1] - pref[i];
            if (l == r) ans += 2;
            else if (Math.abs(l - r) == 1) ans++;
        }

        return ans;
    }
}
