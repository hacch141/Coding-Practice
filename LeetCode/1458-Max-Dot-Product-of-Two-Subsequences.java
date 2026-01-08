// 1458. Max Dot Product of Two Subsequences

class Solution {
    public int[][] dp;

    public int solve(int ind1, int n1, int ind2, int n2, int[] nums1, int[] nums2) {
        if (ind1 >= n1 || ind2 >= n2) return (int)(-1e9);

        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int curr = nums1[ind1] * nums2[ind2];
        int take = curr + solve(ind1 + 1, n1, ind2 + 1, n2, nums1, nums2);
        int skip1 = solve(ind1 + 1, n1, ind2, n2, nums1, nums2);
        int skip2 = solve(ind1, n1, ind2 + 1, n2, nums1, nums2);

        return dp[ind1][ind2] = IntStream.of(curr, take, skip1, skip2).max().getAsInt();
    }

    public int maxDotProduct(int[] nums1, int[] nums2) {
        int n1 = nums1.length, n2 = nums2.length;
        dp = new int[n1][n2];
        for (int i = 0; i < n1; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(0, n1, 0, n2, nums1, nums2);
    }
}
