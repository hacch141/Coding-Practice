// 407. Trapping Rain Water II

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

    public int trapRainWater(int[][] heightMap) {
        int n = heightMap.length, m = heightMap[0].length;
        if (n == 1 || m == 1) return 0;

        boolean[][] vis = new boolean[n][m];
        PriorityQueue<Cell> pq = new PriorityQueue<>(cmp);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    pq.offer(new Cell(i, j, heightMap[i][j]));
                    vis[i][j] = true;
                }
            }
        }

        int water = 0;
        while (!pq.isEmpty()) {
            Cell curr = pq.poll();
            int x = curr.row, y = curr.col, h = curr.height;
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    if (h > heightMap[nx][ny]) water += h - heightMap[nx][ny];
                    pq.offer(new Cell(nx, ny, Math.max(h, heightMap[nx][ny])));
                }
            }
        }

        return water;
    }
}
