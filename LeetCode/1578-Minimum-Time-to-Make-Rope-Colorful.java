// 1578. Minimum Time to Make Rope Colorful

class Solution {
    public int minCost(String colors, int[] neededTime) {
        int n = neededTime.length;
        int l = 0, r = 0, ans = 0;
        while (r < n) {
            int mx = Integer.MIN_VALUE;
            while (r < n && colors.charAt(l) == colors.charAt(r)) {
                ans += neededTime[r];
                mx = Math.max(mx, neededTime[r]);
                r++;
            }
            ans -= mx;
            l = r;
        }
        return ans;
    }
}
