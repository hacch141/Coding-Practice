// 2211. Count Collisions on a Road

class Solution {
    public int countCollisions(String directions) {
        int n = directions.length();
        int l = 0, r = n - 1;
        while (l <= r && directions.charAt(l) == 'L') l++;
        while (l <= r && directions.charAt(r) == 'R') r--;

        int ans = 0;
        for (int i = l; i <= r; i++) {
            ans += directions.charAt(i) != 'S' ? 1 : 0;
        }

        return ans;
    }
}
