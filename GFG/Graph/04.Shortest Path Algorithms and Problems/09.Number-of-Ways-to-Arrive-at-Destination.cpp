// Number of Ways to Arrive at Destination

class Solution {
    long MOD = (int)1e9 + 7;
    long INF = Long.MAX_VALUE;

    public int countPaths(int n, int[][] roads) {
        List<int[]>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int[] r : roads) {
            int u = r[0], v = r[1], t = r[2];
            adj[u].add(new int[]{v, t});
            adj[v].add(new int[]{u, t});
        }

        long[] dist = new long[n];
        long[] dp = new long[n];
        Arrays.fill(dist, INF);

        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(a[0], b[0]));
        pq.add(new long[]{0, 0});

        dist[0] = 0;
        dp[0] = 1;

        while (!pq.isEmpty()) {
            long[] curr = pq.poll();
            long ut = curr[0];
            int u = (int)curr[1];
            for (int[] edge : adj[u]) {
                int v = edge[0];
                long vt = (long)edge[1];
                long newTime = ut + vt;
                if (newTime < dist[v]) {
                    dist[v] = newTime;
                    dp[v] = dp[u];
                    pq.add(new long[]{newTime, v});
                }
                else if (newTime == dist[v]) {
                    dp[v] = (dp[u] + dp[v]) % MOD;
                }
            }
        }

        return (int)dp[n - 1];
    }
}

// =========================================================================

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<vector<pair<int,int>>> adj(n);
        for(auto i : roads) {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        vector<int> ways(n,0);
        vector<long> dist(n,INT_MAX);
        dist[0] = 0;
        ways[0] = 1;
        int mod = 1e9 + 7;
        
        while(!pq.empty()) {
            int u = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            for(auto it : adj[u]) {
                int v = it.first;
                int w = it.second;
                if(dis + w < dist[v]) {
                    dist[v] = dis + w;
                    ways[v] = ways[u];
                    pq.push({dist[v],v});
                }
                else if((dis + w)%mod == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }
        
        return ways[n-1];
    }
};

// T : O(E * LogV)
// S : O(n)
