// 3075. Maximize Happiness of Selected Children

class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        int n = happiness.length;
        long ans = 0, dec = 0;
        for (int i = 0; i < k; i++) {
            ans += Math.max(0, happiness[n - 1 - i] - dec);
            dec++;
        }
        return ans;
    }
}
