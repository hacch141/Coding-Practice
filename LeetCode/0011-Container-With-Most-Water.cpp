// 11. Container With Most Water

class Solution {
    public int maxArea(int[] height) {
        int l = 0, r = height.length - 1, ans = 0;
        while (l < r) {
            int h = Math.min(height[l], height[r]);
            ans = Math.max(ans, h * (r - l));
            if (height[l] <= height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return ans;
    }
}
