// 2976. Minimum Cost to Convert String I

class Solution {
    public List<int[]>[] adj;
    public int INF = (int)1e9;

    public void getMinDist(int start, int[] dist) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        pq.add(new int[]{start, 0});
        dist[start] = 0;
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int u = curr[0];
            int du = curr[1];
            for (int[] edge : adj[u]) {
                int v = edge[0];
                int dv = edge[1];
                int cost = du + dv;
                if (cost < dist[v]) {
                    dist[v] = cost;
                    pq.add(new int[]{v, cost});
                }
            }
        }
    }

    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        adj = new ArrayList[26];
        for (int i = 0; i < 26; i++) adj[i] = new ArrayList<>();

        for (int i = 0; i < original.length; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int c = cost[i];
            adj[u].add(new int[]{v, c});
        }

        int[][] dist = new int[26][26];
        for (int i = 0; i < 26; i++) {
            Arrays.fill(dist[i], INF);
        }

        for (int i = 0; i < 26; i++) {
            getMinDist(i, dist[i]);
        }

        long ans = 0;
        for (int i = 0; i < source.length(); i++) {
            int u = source.charAt(i) - 'a';
            int v = target.charAt(i) - 'a';
            if (dist[u][v] == INF) return -1;
            ans += dist[u][v];
        }

        return ans;
    }
}
