// 1411. Number of Ways to Paint N × 3 Grid

class Solution {
    public char[][] grid;
    public Map<String,Integer> dp;
    public int MOD = (int)1e9 + 7;

    public int solve(int i, int j, int n) {
        if (i == n) return 1;

        int ans = 0;
        if (j == 3) {
            String key = (char)('0' + i) + "_" + grid[i][0] + "_" + grid[i][1] + "_" + grid[i][2];
            if (dp.containsKey(key)) return dp.get(key);
            ans = solve(i + 1, 0, n);
            dp.put(key, ans);
            return ans;
        }

        for (char color : new char[]{'R', 'Y', 'G'}) {
            if (i > 0 && grid[i - 1][j] == color) continue;
            if (j > 0 && grid[i][j - 1] == color) continue;
            grid[i][j] = color;
            ans = (ans + solve(i, j + 1, n)) % MOD;
        }
        return ans;
    }

    public int numOfWays(int n) {
        grid = new char[n][3];
        dp = new HashMap<>();
        return solve (0, 0, n);
    }
}
