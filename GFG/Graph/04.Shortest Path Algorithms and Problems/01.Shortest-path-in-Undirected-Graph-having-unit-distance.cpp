// Shortest path in Undirected Graph having unit distance

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
