// 3650. Minimum Cost Path with Edge Reversals

class Pair {
    int node, d;
    public Pair(int node, int d) {
        this.node = node;
        this.d = d;
    }
}

class Solution {
    public int minCost(int n, int[][] edges) {
        List<Pair>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].add(new Pair(v, w));
            adj[v].add(new Pair(u, 2 * w));
        }

        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Integer.compare(a.d, b.d));
        pq.add(new Pair(0, 0));
        dist[0] = 0;

        while (!pq.isEmpty()) {
            Pair curr = pq.poll();
            int u = curr.node;
            int du = curr.d;
            for (Pair p : adj[u]) {
                int v = p.node;
                int dv = p.d;
                if (du + dv < dist[v]) {
                    dist[v] = du + dv;
                    pq.add(new Pair(v, dist[v]));
                }
            }
        }

        return dist[n - 1] != Integer.MAX_VALUE ? dist[n - 1] : -1;
    }
}
