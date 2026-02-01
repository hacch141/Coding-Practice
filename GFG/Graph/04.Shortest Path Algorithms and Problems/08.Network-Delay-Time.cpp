// Network Delay Time

class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {

        ArrayList<int[]>[] adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int[] t : times) {
            int u = t[0];
            int v = t[1];
            int w = t[2];
            adj[u].add(new int[]{v, w});
        }

        // PQ stores {time, node}
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));

        int[] time = new int[n + 1];
        Arrays.fill(time, (int) 1e9);

        time[k] = 0;
        pq.offer(new int[]{0, k});

        // Dijkstra
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int ut = cur[0];
            int u = cur[1];

            // optional optimization
            if (ut > time[u]) continue;

            for (int[] it : adj[u]) {
                int v = it[0];
                int wt = it[1];

                if (ut + wt < time[v]) {
                    time[v] = ut + wt;
                    pq.offer(new int[]{time[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (time[i] == (int) 1e9) {
                return -1;
            }
            ans = Math.max(ans, time[i]);
        }

        return ans;
    }
}

// =============================================================================

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i : times) {
            adj[i[0]].push_back({i[1],i[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> time(n+1,1e9);
        time[k] = 0;

        while(!pq.empty()) {
            int u = pq.top().second;
            int ut = pq.top().first;
            pq.pop();

            for(auto it : adj[u]) {
                int v = it.first;
                int vt = it.second;
                if(ut + vt < time[v]) {
                    time[v] = ut + vt;
                    pq.push({time[v],v});
                }
            }
        }

        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(time[i] == 1e9) {
                return -1;
            }
            ans = max(ans,time[i]);
        }

        return ans;
    }
};

// T : O(E * LogV)
// S : O(n)
