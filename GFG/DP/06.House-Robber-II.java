// 213. House Robber II

class Solution {

    private int solve(int[] nums) {

        int prev2 = 0;
        int prev = nums[0];

        for (int i = 1; i < nums.length; i++) {

            int pick = nums[i] + prev2;

            int notPick = prev;

            int curr = Math.max(pick, notPick);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    public int rob(int[] nums) {

        int n = nums.length;

        if (n == 1) return nums[0];

        int[] temp = new int[n - 1];
        int[] temp2 = new int[n - 1];

        int idx1 = 0;
        int idx2 = 0;

        for (int i = 0; i < n; i++) {

            if (i != 0) {
                temp[idx1++] = nums[i];
            }

            if (i != n - 1) {
                temp2[idx2++] = nums[i];
            }
        }

        return Math.max(solve(temp), solve(temp2));
    }
}
