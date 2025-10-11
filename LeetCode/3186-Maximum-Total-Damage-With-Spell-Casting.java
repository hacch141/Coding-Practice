// 3186. Maximum Total Damage With Spell Casting

class Solution {
    public long solve(int ind, int n, List<Integer> uniquePower, Map<Integer,Integer> freq, long[] dp) {
        if (ind >= n) return 0;
        if (dp[ind] != -1) return dp[ind];

        long nottake = solve(ind + 1, n, uniquePower, freq, dp);
        long take = ((long)uniquePower.get(ind) * freq.get(uniquePower.get(ind)));

        int nxtInd = ind;
        while (nxtInd < n && uniquePower.get(nxtInd) - uniquePower.get(ind) <= 2) nxtInd++;

        take += solve(nxtInd, n, uniquePower, freq, dp);

        return dp[ind] = Math.max(take, nottake);
    }

    public long maximumTotalDamage(int[] power) {
        Map<Integer,Integer> freq = new HashMap<>();
        for (int p : power) {
            freq.put(p, freq.getOrDefault(p, 0) + 1);
        }

        List<Integer> uniquePower = new ArrayList<>(freq.keySet());
        Collections.sort(uniquePower);

        long[] dp = new long[uniquePower.size()];
        Arrays.fill(dp, -1);

        return solve(0, uniquePower.size(), uniquePower, freq, dp);
    }
}
