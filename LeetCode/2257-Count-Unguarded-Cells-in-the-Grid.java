// 2257. Count Unguarded Cells in the Grid

class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        char[][] grid = new char[m][n];
        for (int i = 0; i < m; i++) {
            Arrays.fill(grid[i], '.');
        }

        boolean[][] vis_hor = new boolean[m][n];
        boolean[][] vis_ver = new boolean[m][n];
        boolean[][] vis = new boolean[m][n];

        for (int[] g : guards) {
            vis_hor[g[0]][g[1]] = vis_ver[g[0]][g[1]] = vis[g[0]][g[1]] = true;
            grid[g[0]][g[1]] = 'G';
        }

        for (int[] w : walls) {
            vis_hor[w[0]][w[1]] = vis_ver[w[0]][w[1]] = vis[w[0]][w[1]] = true;
            grid[w[0]][w[1]] = 'W';
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 'G') continue;

                // expand horizontally
                int left = j - 1, right = j + 1;
                while (left >= 0 && !vis_hor[i][left] && grid[i][left] == '.') {
                    vis_hor[i][left] = vis[i][left] = true;
                    left--;
                }
                while (right < n && !vis_hor[i][right] && grid[i][right] == '.') {
                    vis_hor[i][right] = vis[i][right] = true;
                    right++;
                }

                // expand vertically
                int up = i - 1, down = i + 1;
                while (up >= 0 && !vis_ver[up][j] && grid[up][j] == '.') {
                    vis_ver[up][j] = vis[up][j] = true;
                    up--;
                }
                while (down < m && !vis_ver[down][j] && grid[down][j] == '.') {
                    vis_ver[down][j] = vis[down][j] = true;
                    down++;
                }
            }
        }

        int not_guarded = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                not_guarded += vis[i][j] == false ? 1 : 0;
            }
        }

        return not_guarded;
    }
}
