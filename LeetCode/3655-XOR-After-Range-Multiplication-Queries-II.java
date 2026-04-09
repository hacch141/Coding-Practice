// 3655. XOR After Range Multiplication Queries II

class Solution {
    int MOD = (int)(1e9 + 7);

    public int numPow(int num, int pow) {
        int ans = 1;
        while (pow > 0) {
            if ((pow & 1) == 1) {
                ans = (int)((1L * ans * num) % MOD);
            }
            num = (int)((1L * num * num) % MOD);
            pow >>= 1;
        }
        return ans;
    }

    public int xorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.length;
        
        Map<Integer,List<int[]>> mp = new HashMap<>();
        for (int[] q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k * k >= n) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (int)((1L * nums[i] * v) % MOD);
                }
            }
            else {
                mp.computeIfAbsent(k, a -> new ArrayList<>()).add(new int[]{l, r, v});
            }
        }

        for (Map.Entry<Integer,List<int[]>> e : mp.entrySet()) {
            int k = e.getKey();

            int[] diff = new int[n];
            Arrays.fill(diff, 1);

            for (int[] q : e.getValue()) {
                int l = q[0], r = q[1], v = q[2];
                diff[l] = (int)((1L * diff[l] * v) % MOD);
                int steps = (r - l) / k;
                int next = l + (steps + 1) * k;
                if (next < n) diff[next] = (int)((1L * diff[next] * numPow(v, MOD - 2)) % MOD);
            }

            for (int i = k; i < n; i++) {
                diff[i] = (int)((1L * diff[i] * diff[i - k]) % MOD);
            }

            for (int i = 0; i < n; i++) {
                nums[i] = (int)((1L * nums[i] * diff[i]) % MOD);
            }
        }

        int ans = 0;
        for (int a : nums) {
            ans ^= a;
        }

        return ans;
    }
}
