// 2483. Minimum Penalty for a Shop

class Solution {
    public int bestClosingTime(String customers) {
        int n = customers.length(), penalty = 0;
        for (char ch : customers.toCharArray()) {
            penalty += ch == 'N' ? 1 : 0;
        }

        int ans = n, mn = penalty;
        for (int i = n - 1; i >= 0; i--) {
            penalty += customers.charAt(i) == 'Y' ? 1 : -1;
            if (penalty <= mn) {
                ans = i;
                mn = penalty;
            }
        }
        return ans;
    }
}
