// 3651. Minimum Cost Path with Teleportations

class Solution {
    public int INF = (int)1e9;

    public int minCost(int[][] grid, int k) {
        int n = grid.length, m = grid[0].length;

        List<int[]> cells = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cells.add(new int[]{i, j, grid[i][j]});
            }
        }
        cells.sort((a, b) -> a[2] - b[2]);

        int[][][] dist = new int[n][m][k + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Arrays.fill(dist[i][j], INF);
            }
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[3] - b[3]);
        pq.add(new int[]{0, 0, k, 0});
        dist[0][0][k] = 0;

        int[] cntK = new int[k + 1];

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int i = curr[0], j = curr[1], K = curr[2], du = curr[3];
            if (i + 1 < n) {
                int nu = du + grid[i + 1][j];
                if (nu < dist[i + 1][j][K]) {
                    dist[i + 1][j][K] = nu;
                    pq.add(new int[]{i + 1, j, K, dist[i + 1][j][K]});
                }
            }
            if (j + 1 < m) {
                int nu = du + grid[i][j + 1];
                if (nu < dist[i][j + 1][K]) {
                    dist[i][j + 1][K] = nu;
                    pq.add(new int[]{i, j + 1, K, dist[i][j + 1][K]});
                }
            }
            if (K > 0) {
                while (cntK[K] < cells.size() && cells.get(cntK[K])[2] <= grid[i][j]) {
                    int[] cell = cells.get(cntK[K]++);
                    int iv = cell[0], jv = cell[1], c = cell[2];
                    if (grid[i][j] < c) break;
                    if (dist[i][j][K] < dist[iv][jv][K - 1]) {
                        dist[iv][jv][K - 1] = dist[i][j][K];
                        pq.add(new int[]{iv, jv, K - 1, dist[i][j][K]});
                    }
                }
            }
        }

        int ans = (int)1e9;
        for (int i = 0; i <= k; i++) {
            ans = Math.min(ans, dist[n - 1][m - 1][i]);
        }

        return ans;
    }
}
