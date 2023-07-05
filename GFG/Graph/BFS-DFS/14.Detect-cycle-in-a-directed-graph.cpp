// Detect cycle in a directed graph

class Solution {
    
  private:
    bool dfs(int u, vector<int> adj[], vector<int>& vis, vector<int>& pathVis) {
        vis[u] = 1;
        pathVis[u] = 1;
        
        for(auto v : adj[u]) {
            if(!vis[v]) {
                if(dfs(v,adj,vis,pathVis) == true) return true;
            }
            else {
                if(pathVis[v]) return true;
            }
        }
        pathVis[u] = 0;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dfs(i,adj,vis,pathVis) == true) return true;
            }
        }
        
        return false;
    }
};

// T : O(V + 2*E)
// S : O(V)
