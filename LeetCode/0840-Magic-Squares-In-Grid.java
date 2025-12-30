// 840. Magic Squares In Grid

class Solution {
    public boolean isMagicSquare(int row, int col, int[][] grid) {
        int sum = -1, currSum = 0;
        boolean[] vis = new boolean[10];

        for (int i = 0; i < 3; i++) {
            currSum = 0;
            for (int j = 0; j < 3; j++) {
                currSum += grid[row + i][col + j];
                if (grid[row + i][col + j] > 9) return false;
                vis[grid[row + i][col + j]] = true;
            }
            if (sum == -1) sum = currSum;
            else if (currSum != sum) return false;
        }

        for (int i = 1; i <= 9; i++) {
            if (!vis[i]) return false;
        }

        for (int j = 0; j < 3; j++) {
            currSum = 0;
            for (int i = 0; i < 3; i++) {
                currSum += grid[row + i][col + j];
            }
            if (currSum != sum) return false;
        }

        currSum = 0;
        for (int i = 0; i < 3; i++) {
            currSum += grid[row + i][col + i];
        }
        if (currSum != sum) return false;

        currSum = 0;
        for (int i = 0; i < 3; i++) {
            currSum += grid[row + i][col + (2 - i)];
        }
        if (currSum != sum) return false;

        return true;
    }

    public int numMagicSquaresInside(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                ans += isMagicSquare(i, j, grid) ? 1 : 0;
            }
        }
        return ans;
    }
}
