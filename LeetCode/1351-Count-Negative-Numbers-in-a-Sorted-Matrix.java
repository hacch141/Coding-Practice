// 1351. Count Negative Numbers in a Sorted Matrix

class Solution {
    public int getInd(int[] arr, int n) {
        int ans = n;
        int l = 0, h = n - 1;
        while (l <= h) {
            int m = (h - l) / 2 + l;
            if (arr[m] < 0) {
                ans = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }

    public int countNegatives(int[][] grid) {
        int ans = 0, n = grid[0].length;
        for (int[] g : grid) {
            ans += n - getInd(g, n);
        }
        return ans;
    }
}
