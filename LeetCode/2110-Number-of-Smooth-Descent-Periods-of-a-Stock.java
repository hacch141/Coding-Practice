// 2110. Number of Smooth Descent Periods of a Stock

class Solution {
    public long getDescentPeriods(int[] prices) {
        long ans = 0, cnt = 0;
        int n = prices.length;
        for (int i = 0; i < n; i++) {
            if (i == 0 || prices[i] == prices[i - 1] - 1) {
                cnt++;
            }
            else {
                ans += (cnt * (cnt + 1)) / 2;
                cnt = 1;
            }
        }
        ans += (cnt * (cnt + 1)) / 2;
        return ans;
    }
}
