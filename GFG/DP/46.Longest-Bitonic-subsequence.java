// Longest Bitonic subsequence

class Solution {
    public static int longestBitonicSequence(int n, int[] nums) {
        int[] lis = new int[n];
        int[] lds = new int[n];
        Arrays.fill(lis, 1);
        Arrays.fill(lds, 1);

        // LIS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    lis[i] = Math.max(lis[i], 1 + lis[j]);
                }
            }
        }

        // LDS
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[j] < nums[i]) {
                    lds[i] = Math.max(lds[i], 1 + lds[j]);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            // both increasing and decreasing parts exist
            if (lis[i] > 1 && lds[i] > 1) {
                ans = Math.max(ans, lis[i] + lds[i] - 1);
            }
        }

        return ans;
    }
}
