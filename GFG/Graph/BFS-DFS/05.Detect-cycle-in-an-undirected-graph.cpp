// Detect cycle in an undirected graph

// BFS
class Solution {
    
  private:
    bool bfs(int u, vector<int> adj[], vector<int>& vis) {
        vis[u] = 1;
        
        queue<pair<int,int>> q;
        q.push({u,-1});
        
        while(!q.empty()) {
            int u = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto v : adj[u]) {
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push({v,u});
                }
                else {
                    if(v != parent) return true;
                }
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
                if(bfs(i,adj,vis)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

// T : O(V + 2*E)
// S : O(V)
