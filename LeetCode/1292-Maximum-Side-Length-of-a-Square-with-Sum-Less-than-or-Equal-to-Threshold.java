// 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold

class Solution {
    public int getArea(int[][] mat, int r1, int c1, int r2, int c2) {
        int n = mat.length, m = mat[0].length;
        int area = mat[r2][c2];
        if (r1 > 0) area -= mat[r1 - 1][c2];
        if (c1 > 0) area -= mat[r2][c1 - 1];
        if (r1 > 0 && c1 > 0) area += mat[r1 - 1][c1 - 1];
        return area;
    }

    public int maxSideLength(int[][] mat, int threshold) {
        int n = mat.length, m = mat[0].length;
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                mat[i][j] += mat[i][j - 1];
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                mat[i][j] += mat[i - 1][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; i + k < n && j + k < m; k++) {
                    int currArea = getArea(mat, i, j, i + k, j + k);
                    if (currArea <= threshold) {
                        ans = Math.max(ans, k + 1);
                    }
                }
            }
        }

        return ans;
    }
}
