// 417. Pacific Atlantic Water Flow

class Solution {
    int[] dx = {-1, 0, +1, 0};
    int[] dy = {0, +1, 0, -1};

    boolean isValid(int nx, int ny, int n, int m, boolean[][] vis) {
        return nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny];
    }

    public void dfs(int x, int y, int n, int m, boolean[][] vis, int[][] heights) {
        vis[x][y] = true;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (isValid(nx, ny, n, m, vis) && heights[nx][ny] >= heights[x][y]) {
                dfs(nx, ny, n, m, vis, heights);
            }
        }
    }

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int n = heights.length, m = heights[0].length;
        boolean[][] atlantic = new boolean[n][m];
        boolean[][] pacific = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            dfs(i, 0, n, m, pacific, heights);
            dfs(i, m - 1, n, m, atlantic, heights);
        }
        for (int j = 0; j < m; j++) {
            dfs(0, j, n, m, pacific, heights);
            dfs(n - 1, j, n, m, atlantic, heights);
        }

        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.add(Arrays.asList(i, j));
                }
            }
        }

        return ans;
    }
}

// ========================================================================

class Pair {
    int a, b;
    public Pair(int a, int b) {
        this.a = a;
        this.b = b;
    }
}

class Solution {
    int[] dx = {-1, 0, +1, 0};
    int[] dy = {0, +1, 0, -1};

    boolean isValid(int nx, int ny, int n, int m, boolean[][] vis) {
        return nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny];
    }

    public void bfs(Queue<Pair> q, int[][] heights, boolean[][] vis, boolean[][] ocean) {
        int n = heights.length, m = heights[0].length;
        while (!q.isEmpty()) {
            int sz = q.size();
            while (sz-- > 0) {
                Pair curr = q.poll();
                int x = curr.a, y = curr.b;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (isValid(nx, ny, n, m, vis) && heights[nx][ny] >= heights[x][y]) {
                        vis[nx][ny] = true;
                        ocean[nx][ny] = true;
                        q.offer(new Pair(nx, ny));
                    }
                }
            }
        }
    }

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int n = heights.length, m = heights[0].length;
        boolean[][] atlantic = new boolean[n][m];
        boolean[][] vis = new boolean[n][m];

        Queue<Pair> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            atlantic[i][m - 1] = vis[i][m - 1] = true;
            q.offer(new Pair(i, m - 1));
        }
        for (int j = 0; j < m; j++) {
            atlantic[n - 1][j] = vis[n - 1][j] = true;
            q.offer(new Pair(n - 1, j));
        }
        bfs(q, heights, vis, atlantic);

        boolean[][] pacific = new boolean[n][m];
        vis = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            pacific[i][0] = vis[i][0] = true;
            q.offer(new Pair(i, 0));
        }
        for (int j = 0; j < m; j++) {
            pacific[0][j] = vis[0][j] = true;
            q.offer(new Pair(0, j));
        }
        bfs(q, heights, vis, pacific);

        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.add(Arrays.asList(i, j));
                }
            }
        }

        return ans;
    }
}
