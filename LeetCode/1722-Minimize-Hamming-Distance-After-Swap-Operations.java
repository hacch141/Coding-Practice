// 1722. Minimize Hamming Distance After Swap Operations

class DisjointSet {
    int[] sz, parent;

    DisjointSet(int n ) {
        sz = new int[n + 1];
        parent = new int[n + 1];
        Arrays.fill(sz, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    public int findParent(int u) {
        if (parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }

    public void union(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v) {
            return;
        }
        if (sz[ulp_u] >= sz[ulp_v]) {
            parent[ulp_v] = parent[ulp_u];
            sz[ulp_u] += sz[ulp_v];
        }
        else {
            parent[ulp_u] = parent[ulp_v];
            sz[ulp_v] += sz[ulp_u];
        }
    }
}

class Solution {
    public int minimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
        int n = source.length;
        DisjointSet ds = new DisjointSet(n);

        for (int[] swap : allowedSwaps) {
            ds.union(swap[0], swap[1]);
        }

        Map<String, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int par = ds.findParent(i);

            String inc = Arrays.toString(new int[]{par, source[i]});
            mp.put(inc, mp.getOrDefault(inc, 0) + 1);

            String dec = Arrays.toString(new int[]{par, target[i]});
            mp.put(dec, mp.getOrDefault(dec, 0) - 1);
        }

        int missMatchs = 0;
        for (int v : mp.values()) {
            missMatchs += Math.abs(v);
        }

        return missMatchs / 2;
    }
}
