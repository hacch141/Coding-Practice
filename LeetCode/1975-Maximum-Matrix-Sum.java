// 1975. Maximum Matrix Sum

class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int cntNegative = 0, mn = Integer.MAX_VALUE;
        long sum = 0;
        for (int[] row : matrix) {
            for (int cell : row) {
                if (cell < 0) {
                    cntNegative++;
                }
                mn = Math.min(mn, Math.abs(cell));
                sum += Math.abs(cell);
            }
        }
        if (cntNegative % 2 == 1) sum -= 2 * mn;
        return sum;
    }
}
