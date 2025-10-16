// 2598. Smallest Missing Non-negative Integer After Operations

class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        int n = nums.length;
        int[] f = new int[value];
        for (int i : nums) {
            f[((i % value) + value) % value]++;
        }

        int mn = Integer.MAX_VALUE, ind = 0;
        for (int i = 0; i < value; i++) {
            if (f[i] == 0) return i;
            mn = Math.min(mn, f[i]);
        }

        int ans = value * mn;
        for (int i = 0; i < value; i++) {
            if (f[i] > mn) ans++;
            else break;
        }
        
        return ans;
    }
}
