// 787. Cheapest Flights Within K Stops

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        List<int[]>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();

        for (int[] f : flights) {
            int u = f[0], v = f[1], p = f[2];
            adj[u].add(new int[]{v, p});
        }

        int[][] dist = new int[n][k + 1];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dist[i], (int)1e9);
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        pq.add(new int[]{0, -1, src});  // {cost, stops, citty}
        dist[src][0] = 0;

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int cost = curr[0];
            int currK = curr[1];
            int u = curr[2];
            
            if (u == dst) return cost;
            if (currK == k) continue;

            for (int [] edge : adj[u]) {
                int v = edge[0];
                int dv = edge[1];
                int newCost = cost + dv;
                if (newCost < dist[v][currK + 1]) {
                    dist[v][currK + 1] = newCost;
                    pq.add(new int[]{newCost, currK + 1, v});
                }
            }
        }

        return -1;
    }
}
