// Shortest path in Directed Acyclic Graph

class Solution {
    
  private:
      void topo(int u, vector<vector<pair<int,int>>>& adj, vector<int>& vis, stack<int>& st) {
          vis[u] = 1;
          for(auto it : adj[u]) {
              int v = it.first;
              if(!vis[v]) {
                  topo(v,adj,vis,st);
              }
          }
          st.push(u);
      }
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>> adj(N);
        for(auto i : edges) {
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        vector<int> vis(N,0);
        stack<int> st;
        for(int i=0; i<N; i++) {
            if(!vis[i]) {
                topo(i,adj,vis,st);
            }
        }
        
        vector<int> dist(N,1e9);
        dist[0] = 0;
        while(!st.empty()) {
            int u = st.top();
            st.pop();
            for(auto it : adj[u]) {
                int v = it.first;
                int w = it.second;
                if(w + dist[u] < dist[v]) {
                    dist[v] = w + dist[u];
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
// S : O(N + 2*M)
// S : O()
