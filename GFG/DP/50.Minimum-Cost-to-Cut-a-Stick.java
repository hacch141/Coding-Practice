class Solution {
    Map<String,Integer> mp;

    public int solve(int l, int r, int[] cuts) {

        String key = l + "_" + r;
        if (mp.containsKey(key)) return mp.get(key);

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < cuts.length; i++) {
            if (l < cuts[i] && cuts[i] < r) {
                ans = Math.min(ans, r - l + solve(l, cuts[i], cuts) + solve(cuts[i], r, cuts));
            }
        }

        if (ans == Integer.MAX_VALUE) ans = 0;
        mp.put(key, ans);

        return ans;
    }

    public int minCost(int n, int[] cuts) {
        mp = new HashMap<>();
        return solve(0, n, cuts);
    }
}
