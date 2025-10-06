// 778. Swim in Rising Water

class Cell {
    int row, col, height;
    public Cell(int row, int col, int height) {
        this.row = row;
        this.col = col;
        this.height = height;
    }
}


class Solution {
    int[] dx = {-1, 0, +1, 0};
    int[] dy = {0, +1, 0, -1};

    Comparator<Cell> cmp = (a, b) -> {
        return a.height - b.height;
    };

    public int swimInWater(int[][] grid) {
        int n = grid.length;
        boolean[][] vis = new boolean[n][n];

        PriorityQueue<Cell> pq = new PriorityQueue<>(cmp);
        pq.offer(new Cell(0, 0, grid[0][0]));
        vis[0][0] = true;

        int mx = Integer.MIN_VALUE;
        while (!pq.isEmpty()) {
            Cell curr = pq.poll();
            int x = curr.row, y = curr.col, h = curr.height;
            mx = Math.max(mx, h);
            if (x == n - 1 && y == n - 1) return mx;
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.offer(new Cell(nx, ny, grid[nx][ny]));
                }
            }
        }
        return -1;
    }
}

// Binary Search
class Solution {
    int[] dx = {-1, 0, +1, 0};
    int[] dy = {0, +1, 0, -1};

    boolean isValid(int nx, int ny, int n, int m, boolean[][] vis) {
        return nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny];
    }

    boolean dfs(int x, int y, int n, int[][] grid, boolean[][] vis, int mid) {
        if (x == n - 1 && y == n - 1) return true;
        vis[x][y] = true;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (isValid(nx, ny, n, n, vis) && grid[nx][ny] <= mid) {
                if (dfs(nx, ny, n, grid, vis, mid)) return true;
            }
        }
        return false;
    }

    public int swimInWater(int[][] grid) {
        int n = grid.length, l = Integer.MAX_VALUE, h = Integer.MIN_VALUE;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                l = Math.min(l, grid[i][j]);
                h = Math.max(h, grid[i][j]);
            }
        }

        int ans = h;
        while (l <= h) {
            int m = (h - l) / 2 + l;
            boolean[][] vis = new boolean[n][n];
            if (grid[0][0] <= m && dfs(0, 0, n, grid, vis, m)) {
                ans = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        return ans;
    }
}
