// 1970. Last Day Where You Can Still Cross

class DisjointSet {
    int[] sz, parent, lMost, rMost;
    int row, col;
    public DisjointSet(int row, int col) {
        this.row = row;
        this.col = col;
        int n = row * col;
        sz = new int[n];
        parent = new int[n];
        lMost = new int[n];
        rMost = new int[n];
        Arrays.fill(sz, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rMost[i] = lMost[i] = i % col;
        }
    }

    public int findParent(int u) {
        if (parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }

    public boolean union(int u, int v) {
        if (u == v) {
            return (lMost[u] == 0 && rMost[u] == col - 1) ? true : false;
        }

        int parentU = findParent(u);
        int parentV = findParent(v);
        if (parentU == parentV) return false;

        if (sz[parentU] >= sz[parentV]) {
            sz[parentU] += sz[parentV];
            parent[parentV] = parentU;
            lMost[parentU] = Math.min(lMost[parentU], lMost[parentV]);
            rMost[parentU] = Math.max(rMost[parentU], rMost[parentV]);
            return (lMost[parentU] == 0 && rMost[parentU] == col - 1) ? true : false;
        }
        else {
            sz[parentV] += sz[parentU];
            parent[parentU] = parentV;
            lMost[parentV] = Math.min(lMost[parentU], lMost[parentV]);
            rMost[parentV] = Math.max(rMost[parentU], rMost[parentV]);
            return (lMost[parentV] == 0 && rMost[parentV] == col - 1) ? true : false;
        }
    }
}

class Solution {
    public int[] delRow = {-1, 0, +1, 0, -1, -1, +1, +1};
    public int[] delCol = {0, +1, 0, -1, -1, +1, +1, -1};

    public int latestDayToCross(int row, int col, int[][] cells) {
        int n = cells.length;
        DisjointSet ds = new DisjointSet(row, col);
        boolean[][] grid = new boolean[row][col];

        for (int i = 0; i < n; i++) {
            int x = cells[i][0] - 1, y = cells[i][1] - 1;
            grid[x][y] = true;
            if (ds.union(col * x + y, col * x + y)) return i - 1;
            for (int d = 0; d < 8; d++) {
                int dx = x + delRow[d];
                int dy = y + delCol[d];
                if (dx >= 0 && dx < row && dy >= 0 && dy < col && grid[dx][dy]) {
                    if (ds.union(col * x + y, col * dx + dy)) return i;
                }
            }
        }

        return n;
    }
}
