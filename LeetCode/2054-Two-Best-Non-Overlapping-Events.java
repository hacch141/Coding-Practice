// 2054. Two Best Non-Overlapping Events

class Solution {
    public int getNextIndex(int val, int[][] events) {
        int n = events.length;
        int l = 0, h = n - 1, ans = n;
        while (l <= h) {
            int m = (h - l) / 2 + l;
            if (events[m][0] > val) {
                ans = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }

    public int solve(int ind, int n, int cnt, int[][] events, int[][] dp) {
        if (ind >= n || cnt == 0) return 0;
        if (dp[ind][cnt] != -1) return dp[ind][cnt];
        int nottake = solve(ind + 1, n, cnt, events, dp);
        int nextIndex = getNextIndex(events[ind][1], events);
        int take = events[ind][2] + solve(nextIndex, n, cnt - 1, events, dp);
        return dp[ind][cnt] = Math.max(take, nottake);
    }

    public int maxTwoEvents(int[][] events) {
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        int n = events.length;
        int[][] dp = new int[n][3];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(0, n, 2, events, dp);
    }
}
