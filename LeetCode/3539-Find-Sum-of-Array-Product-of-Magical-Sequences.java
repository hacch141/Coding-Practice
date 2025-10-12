// 3539. Find Sum of Array Product of Magical Sequences

class Solution {
    long MOD = 1_000_000_007;
    int N;
    long[] fact, invFact;
    Map<String,Long> memo;

    public long numPow(long num, long pow) {
        long ans = 1;
        while (pow > 0) {
            if ((pow & 1) == 1) {
                ans = (ans * num) % MOD;
            }
            num = (num * num) % MOD;
            pow >>= 1;
        }
        return ans;
    }

    public long nCr(int n, int r) {
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }

    public long solve(long binarySum, int m, int k, int ind, int[] nums) {
        if (m == 0 && Long.bitCount(binarySum) == k) return 1;
        if (m == 0 || ind >= N) return 0;

        String key = binarySum + "_" + m + "_" + k + "_" + ind;
        if (memo.containsKey(key)) return memo.get(key);

        long totalSum = 0;
        totalSum = (totalSum + solve(binarySum >> 1, m, k - (int)(binarySum & 1), ind + 1, nums)) % MOD;
        
        for (int freq = 1; freq <= m; freq++) {
            long newBinarySum = binarySum + freq;
            long prod = solve(newBinarySum >> 1, m - freq, k - (int)(newBinarySum & 1), ind + 1, nums);
            prod = (prod * numPow(nums[ind], freq)) % MOD;
            prod = (prod * nCr(m, freq)) % MOD;
            totalSum = (totalSum + prod) % MOD;
        }

        memo.put(key, totalSum);
        return totalSum;
    }

    public int magicalSum(int m, int k, int[] nums) {
        int n = nums.length;
        N = n;
        memo = new HashMap<>();

        fact = new long[m + 1];
        invFact = new long[m + 1];
        fact[0] = 1;
        for (int i = 1; i <= m; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        for (int i = 0; i <= m; i++) {
            invFact[i] = numPow(fact[i], MOD - 2);
        }

        return (int)solve(0, m, k, 0, nums);
    }
}
// TC : O(n * m^3 * k)
