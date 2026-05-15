// Chocolates Pickup

class Solution {
    public int maxChocolate(int grid[][]) {
        // code here
        int n = grid.length, m = grid[0].length;
        int[][][] dp = new int[n][m][m];
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    if (i == n - 1) {
                        dp[i][j][k] = (j != k ? grid[i][j] + grid[i][k] : grid[i][j]);
                    }
                    else {
                        int curr = Integer.MIN_VALUE;
                        for (int dx = -1; dx <= 1; dx++) {
                            for (int dy = -1; dy <= 1; dy++) {
                                int nj = j + dx, nk = k + dy;
                                if (nj >= 0 && nj < m && nk >= 0 && nk < m) {
                                    curr = Math.max(curr, (j != k ? grid[i][j] + grid[i][k] : grid[i][j]) + dp[i + 1][nj][nk]);
                                }
                            }
                        }
                        dp[i][j][k] = curr;
                    }
                }
            }
        }
        
        return dp[0][0][m - 1];
    }
}
