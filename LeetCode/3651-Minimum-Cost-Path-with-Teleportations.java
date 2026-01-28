// 3651. Minimum Cost Path with Teleportations

class State {
    int i, j, k, cost;
    public State(int i, int j, int k, int cost) {
        this.i = i;
        this.j = j;
        this.k = k;
        this.cost = cost;
    }
}

class Solution {

    public int minCost(int[][] grid, int K) {
        int n = grid.length, m = grid[0].length;
        int INF = (int) 1e9;

        int[][][] dist = new int[n][m][K + 1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                Arrays.fill(dist[i][j], INF);

        List<int[]> cells = new ArrayList<>();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cells.add(new int[]{grid[i][j], i, j});

        cells.sort((a, b) -> Integer.compare(a[0], b[0]));

        PriorityQueue<State> pq = new PriorityQueue<>((a, b) -> Integer.compare(a.cost, b.cost));
        pq.add(new State(0, 0, K, 0));
        dist[0][0][K] = 0;

        int[] used = new int[K + 1];

        while (!pq.isEmpty()) {
            State cur = pq.poll();
            int i = cur.i, j = cur.j, k = cur.k, cost = cur.cost;

            if (cost > dist[i][j][k]) continue;

            if (i == n - 1 && j == m - 1) return cost;

            // Move down
            if (i + 1 < n) {
                int nc = cost + grid[i + 1][j];
                if (nc < dist[i + 1][j][k]) {
                    dist[i + 1][j][k] = nc;
                    pq.add(new State(i + 1, j, k, nc));
                }
            }

            // Move right
            if (j + 1 < m) {
                int nc = cost + grid[i][j + 1];
                if (nc < dist[i][j + 1][k]) {
                    dist[i][j + 1][k] = nc;
                    pq.add(new State(i, j + 1, k, nc));
                }
            }

            // Jump (free)
            if (k > 0) {
                while (used[k] < cells.size() && cells.get(used[k])[0] <= grid[i][j]) {
                    int[] c = cells.get(used[k]++);
                    int x = c[1], y = c[2];
                    if (cost < dist[x][y][k - 1]) {
                        dist[x][y][k - 1] = cost;
                        pq.add(new State(x, y, k - 1, cost));
                    }
                }

            }
        }

        return -1;
    }
}

