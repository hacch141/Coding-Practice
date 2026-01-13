// 3453. Separate Squares I

class Solution {
    public boolean ok(int[][] squares, double mid) {
        double upperArea = 0, lowerArea = 0;
        for (int[] square : squares) {
            double x = square[0], y = square[1], l = square[2];
            if (y >= mid) {
                upperArea += l * l;
            }
            else if (y + l <= mid) {
                lowerArea += l * l;
            }
            else {
                upperArea += (y + l - mid) * l;
                lowerArea += (mid - y) * l;
            }
        }
        return upperArea <= lowerArea;
    }

    public double separateSquares(int[][] squares) {
        double l = 0, h = 0;
        for (int[] square : squares) {
            h = Math.max(h, square[1] + square[2]);
        }

        double ans = 0.0;
        while (l <= h) {
            double m = (h - l) / 2 + l;
            if (ok(squares, m)) {
                ans = m;
                h = m - (1.0/1e6);
            }
            else {
                l = m + (1.0/1e6);
            }
        }

        return ans;
    }
}
