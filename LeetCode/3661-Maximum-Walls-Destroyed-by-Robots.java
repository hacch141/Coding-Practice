// 3661. Maximum Walls Destroyed by Robots

class Solution {
    int[][] dp;

    public int getLR(int left, int right, int[] walls) {
        int lInd = -1, rInd = -1;
        int l = 0, h = walls.length - 1;
        while (l <= h) {
            int m = (h - l) / 2 + l;
            if (walls[m] >= left) {
                lInd = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        l = 0;
        h = walls.length - 1;
        while (l <= h) {
            int m = (h - l) / 2 + l;
            if (walls[m] <= right) {
                rInd = m;
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }
        return (lInd != -1 && rInd != -1) ? rInd - lInd + 1 : 0;
    }

    public int solve(int ind, int n, List<int[]> ranges, int[] walls, int dir) {
        if (ind == n) return 0;

        if (dp[ind][dir] != -1) return dp[ind][dir];

        int l = getLR(Math.max(ranges.get(ind)[0], dir == 1 ? ranges.get(ind - 1)[2] + 1 : Integer.MIN_VALUE), ranges.get(ind)[1], walls) + solve(ind + 1, n, ranges, walls, 0);
        int r = getLR(ranges.get(ind)[1], ranges.get(ind)[2], walls) + solve(ind + 1, n, ranges, walls, 1);

        return dp[ind][dir] = Math.max(l, r);
    }

    public int maxWalls(int[] robots, int[] distance, int[] walls) {
        int n = robots.length;
        List<int[]> lst = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            lst.add(new int[]{robots[i], distance[i]});
        }
        Collections.sort(lst, (a, b) -> Integer.compare(a[0], b[0]));
        
        List<int[]> ranges = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int[] a = lst.get(i);
            int pos = a[0];
            int d = a[1];
            int l = (i - 1 >= 0) ? lst.get(i - 1)[0] + 1 : 1;
            int r = (i + 1 < n) ? lst.get(i + 1)[0] - 1 : (int)1e9;
            ranges.add(new int[]{Math.max(l, pos - d), pos, Math.min(r, pos + d)});
        }

        Arrays.sort(walls);
        dp = new int[n][2];
        for (int i = 0; i < n; i++) dp[i][0] = dp[i][1] = -1;
        return solve(0, n, ranges, walls, 0);
    }
}
