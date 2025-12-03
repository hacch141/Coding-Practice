// 3625. Count Number of Trapezoids II

class Solution {
    public int countTrapezoids(int[][] points) {
        int n = points.length;
        double INF = 1e9 + 7;

        // [slope][intercept]
        Map<Double,Map<Double,Integer>> mp = new HashMap<>();
        // [mid_point][slope]
        Map<List<Double>,Map<Double,Integer>> mp2 = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x2 - x1;
                int dy = y2 - y1;
                double intercept, slope;
                if (dx == 0) {
                    slope = INF;
                    intercept = x1;
                }
                else {
                    slope = (double)dy / dx;
                    // y = mx + c;
                    intercept = (double)(y1 * dx - x1 * dy) / dx;
                }
                if (slope == -0.0) slope = 0.0;
                if (intercept == -0.0) intercept = 0.0;
                mp.computeIfAbsent(slope, k -> new HashMap<>());
                mp.get(slope).put(intercept, mp.get(slope).getOrDefault(intercept, 0) + 1);

                List<Double> l = List.of((double)(x1 + x2) / 2, (double)(y1 + y2) / 2);
                mp2.computeIfAbsent(l, k -> new HashMap<>());
                mp2.get(l).put(slope, mp2.get(l).getOrDefault(slope, 0) + 1);
            }
        }

        int ans = 0;
        for (Map<Double,Integer> mp_intercept : mp.values()) {
            int prev = 0;
            for (int curr : mp_intercept.values()) {
                ans += curr * prev;
                prev += curr;
            }
        }

        for (Map<Double,Integer> mp_slope : mp2.values()) {
            int prev = 0;
            for (int curr : mp_slope.values()) {
                ans -= prev * curr;
                prev += curr;
            }
        }

        return ans;
    }
}
