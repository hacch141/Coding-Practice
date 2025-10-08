// 2300. Successful Pairs of Spells and Potions

class Solution {
    public int lb(int[] potions, long success, int spell) {
        int n = potions.length;
        int l = 0, h = n - 1, ans = n;
        while (l <= h) {
            int m = (h - l) / 2 + l;
            if ((long) spell * potions[m] >= success) {
                ans = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }

    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length, m = potions.length;
        int[] ans = new int[n];
        Arrays.sort(potions);
        for (int i = 0; i < n; i++) {
            int ind = lb(potions, success, spells[i]);
            ans[i] = m - (ind);
        }
        return ans;
    }
}
