// 1895. Largest Magic Square

class Solution {
    public boolean isMagicSquare(int x1, int y1, int x2, int y2, int[][] grid) {
        int sum = -1;
        for (int i = x1; i <= x2; i++) {
            int currSum = 0;
            for (int j = y1; j <= y2; j++) {
                currSum += grid[i][j];
            }
            if (sum == -1) sum = currSum;
            else if (currSum != sum) return false;
        }

        for (int j = y1; j <= y2; j++) {
            int currSum = 0;
            for (int i = x1; i <= x2; i++) {
                currSum += grid[i][j];
            }
            if (currSum != sum) return false;
        }

        int d1 = 0, d2 = 0;
        for (int i = x1; i <= x2; i++) {
            d1 += grid[i][y1 + (i - x1)];
            d2 += grid[i][y2 - (i - x1)];
        }
        if (d1 != sum || d2 != sum) return false;
        return true;
    }

    public int largestMagicSquare(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; i + k < n && j + k < m; k++) {
                    if (isMagicSquare(i, j, i + k, j + k, grid)) {
                        ans = Math.max(ans, k + 1);
                    }
                }
            }
        }
        return ans;
    }
}
