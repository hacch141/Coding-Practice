// Detect cycle in an undirected graph

// DFS
class Solution {
    
  private:
    bool dfs(int u, int parent, vector<int> adj[], vector<int>& vis) {
        vis[u] = 1;
        
        for(auto v : adj[u]) {
            if(!vis[v]) {
                if(dfs(v,u,adj,vis)) return true;
            }
            else {
                if(v != parent) return true;
            }
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dfs(i,-1,adj,vis)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

// T : O(V + 2*E)
// S : O(V)
