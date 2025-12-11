// 3531. Count Covered Buildings

class Point {
    int mx, mn;
    public Point(int a) {
        this.mx = a;
        this.mn = a;
    }
}

class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        Map<Integer,Point> hor = new HashMap<>();
        Map<Integer,Point> ver = new HashMap<>();

        for (int[] b : buildings) {
            int x = b[0], y = b[1];

            hor.computeIfAbsent(y, k -> new Point(x));
            Point p = hor.get(y);
            p.mx = Math.max(p.mx, x);
            p.mn = Math.min(p.mn, x);

            ver.computeIfAbsent(x, k -> new Point(y));
            p = ver.get(x);
            p.mx = Math.max(p.mx, y);
            p.mn = Math.min(p.mn, y);
        }

        int ans = 0;
        for (int[] b : buildings) {
            int x = b[0], y = b[1];
            Point p1 = hor.get(y);
            Point p2 = ver.get(x);
            if (p1.mn < x && x < p1.mx && p2.mn < y && y < p2.mx) ans++;
        }

        return ans;
    }
}
