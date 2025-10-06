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
