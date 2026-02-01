// Cheapest Flights Within K Stops

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

// ============================================================================================

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<vector<pair<int,int>>> adj(n);
        for(auto i: flights) {
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        vector<int> cost(n,1e9);
        cost[src] = 0;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        
        while(!q.empty()) {
            auto it = q.front();
            int u = it.second.first;
            int c = it.second.second;
            int stops = it.first;
            q.pop();
            
            for(auto it : adj[u]) {
                int v = it.first;
                int w = it.second;
                if(w + c < cost[v] && stops<=K) {
                    cost[v] = w + c;
                    q.push({stops+1,{v,cost[v]}});
                }
            }
        }
        
        return cost[dst] != 1e9 ? cost[dst] : -1; 
    }
};

// T : O(E)   Additional log(N) of time eliminated here because we’re using a simple queue rather than a priority queue which is usually used in Dijkstra’s Algorithm
// S : O(V + E)
