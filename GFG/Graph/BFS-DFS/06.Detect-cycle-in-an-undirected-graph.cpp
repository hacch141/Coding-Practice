// Detect cycle in an undirected graph

class Solution {
    private boolean dfs(int u, int par, List<List<Integer>> adj, boolean[] vis) {
        vis[u] = true;
        for (int v : adj.get(u)) {
            if (v == par) continue;
            if (vis[v]) return true;
            if (dfs(v, u, adj, vis)) return true;
        }
        return false;
    }

    // Function to detect cycle in an undirected graph
    public boolean isCycle(List<List<Integer>> adj) {
        int n = adj.size();
        boolean[] vis = new boolean[n];
        for (int u = 0; u < n; u++) {
            if (!vis[u]) {
                if (dfs(u, -1, adj, vis)) return true;
            }
        }
        return false;
    }
}

// =============================================================

// DFS
class Solution {
  public:
    bool dfs(int u, int par, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[u] = true;
        for(auto &v : adj[u]) {
            if(v == par) continue;
            if(vis[v]) return true;
            if(dfs(v, u, adj, vis)) return true;
        }
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> vis(n, false);
        for(int u = 0; u < n; u++) {
            if(!vis[u] && dfs(u, -1, adj, vis)) return true;
        }
        return false;
    }
};

// T : O(V + 2*E)
// S : O(V)
