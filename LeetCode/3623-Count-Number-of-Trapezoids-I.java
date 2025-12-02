// 3623. Count Number of Trapezoids I

class Solution {
    public long Nc2(long n) {
        return (n * (n - 1L)) / 2L;
    }

    public int countTrapezoids(int[][] points) {
        Map<Integer,Integer> mp = new HashMap<>();
        for (int[] p : points) {
            mp.put(p[1], mp.getOrDefault(p[1], 0) + 1);
        }

        long prev = 0, ans = 0, MOD = 1_000_000_007;
        for (Map.Entry<Integer,Integer> e : mp.entrySet()) {
            long curr = Nc2(e.getValue());
            ans = (ans + (prev * curr)) % MOD;
            prev += curr;
        }

        return (int)ans;
    }
}
