// Detect cycle in an undirected graph

// BFS
class Solution {
  public:
    bool bfs(int u, int par, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[u] = true;
        
        queue<pair<int,int>> q;
        q.push({u, par});
        
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                auto curr = q.front();
                q.pop();
                int u = curr.first, par = curr.second;
                for(auto &v : adj[u]) {
                    if(v == par) continue;
                    if(vis[v]) return true;
                    vis[v] = true;
                    q.push({v, u});
                }
            }
        }
        
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> vis(n, false);
        for(int u = 0; u < n; u++) {
            if(!vis[u])  {
                if(bfs(u, -1, adj, vis)) return true;
            }
        }
        return false;
    }
};

// T : O(V + 2*E)
// S : O(V)
