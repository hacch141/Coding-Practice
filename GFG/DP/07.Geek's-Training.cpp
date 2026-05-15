// Geek's Training

// Memoization
class Solution {
    public int maximumPoints(int mat[][]) {
        // code here
        int n = mat.length;
        int[][] dp = new int[n][3];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 0) {
                    dp[i][j] = mat[i][j];
                }
                else {
                    int prev = 0;
                    for (int k = 0; k < 3; k++) {
                        if (k != j) {
                            prev = Math.max(prev, dp[i - 1][k]);
                        }
                    }
                    dp[i][j] = mat[i][j] + prev;
                }
            }
        }
        
        return Math.max(Math.max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
    }
}
