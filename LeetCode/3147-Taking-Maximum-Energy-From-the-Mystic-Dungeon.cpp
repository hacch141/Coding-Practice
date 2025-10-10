// 3147. Taking Maximum Energy From the Mystic Dungeon

class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int n = energy.length, ans = Integer.MIN_VALUE;
        for (int i = n - 1; i >= Math.max(0, n - k); i--) {
            int curr = 0;
            for (int j = i; j >=0; j -= k) {
                curr += energy[j];
                ans = Math.max(ans, curr);
            }
        }
        return ans;
    }
}
