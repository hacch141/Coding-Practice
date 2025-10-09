// 3494. Find the Minimum Amount of Time to Brew Potions

class Solution {
    public long minTime(int[] skill, int[] mana) {
        int n = skill.length, m = mana.length;
        long[] last = new long[n];
        for (int i = 0; i < m; i++) {
            long mx = 0;
            for (int j = 0; j < n; j++) {
                mx = Math.max(mx, last[j]) + ((long)skill[j] * mana[i]);
            }
            last[n - 1] = mx;
            for (int j = n - 2; j >= 0; j--) {
                last[j] = last[j + 1] - ((long)skill[j + 1] * mana[i]);
            }
        }
        return last[n - 1];
    }
}
