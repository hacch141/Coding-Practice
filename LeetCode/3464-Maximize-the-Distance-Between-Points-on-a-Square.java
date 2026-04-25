// 3464. Maximize the Distance Between Points on a Square

class Solution {
    public int lb(long curr, List<Long> exp) {
        int l = 0, h = exp.size() - 1, ans = -1;
        while (l <= h) {
            int m = (h - l) / 2 + l;
            if (exp.get(m) >= curr) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }

    public boolean ok(long m, long k, long side, List<Long> lst) {
        long n = lst.size();
        
        List<Long> exp = new ArrayList<>(lst);
        for (long a : lst) exp.add(4L * side + a);

        for (int i = 0; i < n; i++) {
            long currInd = i, curr = exp.get(i);
            long last = curr + 4 * side - m;
            boolean f = true;
            for (int j = 0; j < k - 1; j++) {
                int nextInd = lb(curr + m, exp);
                if (nextInd == -1 || exp.get(nextInd) > last) {
                    f = false;
                    break;
                }
                curr = exp.get(nextInd);
                currInd = nextInd;
            }
            if (f) return true;
        }
        return false;
    }

    public int maxDistance(int side, int[][] points, int k) {
        List<Long> lst = new ArrayList<>();
        for (int[] p : points) {
            int x = p[0];
            int y = p[1];
            if (y == 0) {
                lst.add((long)x);
            }
            else if (x == side) {
                lst.add(1L * side + y);
            }
            else if (y == side) {
                lst.add(2L * side + (side - x));
            }
            else {
                lst.add(3L * side + (side - y));
            }
        }
        Collections.sort(lst);

        long l = 1, h = 4L * side;
        long ans = 1;
        while (l <= h) {
            long m = (h - l) / 2 + l;
            if (ok(m, (long)k, (long)side, lst)) {
                ans = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return (int)ans;
    }
}
