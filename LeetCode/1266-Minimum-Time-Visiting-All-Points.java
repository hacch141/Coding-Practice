// 1266. Minimum Time Visiting All Points

class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int n = points.length, ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int dx = Math.abs(points[i][0] - points[i + 1][0]);
            int dy = Math.abs(points[i][1] - points[i + 1][1]);
            ans += Math.max(dx, dy);
        }
        return ans;
    }
}
