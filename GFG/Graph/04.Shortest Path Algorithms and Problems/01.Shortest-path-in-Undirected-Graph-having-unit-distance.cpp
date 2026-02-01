// Shortest path in Undirected Graph having unit distance

class Solution {
    public int[] shortestPath(int[][] edges, int N, int M, int src) {
        ArrayList<Integer>[] adj = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int[] e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].add(v);
            adj[v].add(u);
        }

        int[] dist = new int[N];
        Arrays.fill(dist, (int) 1e9);
        dist[src] = 0;

        Queue<Integer> q = new LinkedList<>();
        q.offer(src);

        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : adj[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    q.offer(v);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (dist[i] == (int) 1e9) {
                dist[i] = -1;
            }
        }

        return dist;
    }
}

// ================================================================

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> adj(N);
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> dist(N,1e9);
        dist[src] = 0;
        
        queue<int> q;
        q.push(src);
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto v : adj[u]) {
                if(1 + dist[u] < dist[v]) {
                    dist[v] = 1 + dist[u];
                    q.push(v);
                }
            }
        }
        
        for(int i=0; i<N; i++) {
            if(dist[i] == 1e9) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};

// T : O(N + 2*M)
// S : O(N + M)
