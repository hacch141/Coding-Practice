// Detect cycle in a directed graph

class Solution {
    private boolean dfs(int u, List<List<Integer>> adj, boolean[] vis, boolean[] pathVis) {
        vis[u] = true;
        pathVis[u] = true;

        for (int v : adj.get(u)) {
            if (pathVis[v]) return true;
            if (vis[v]) continue;
            if (dfs(v, adj, vis, pathVis)) return true;
        }

        pathVis[u] = false; // backtrack
        return false;
    }

    // Function to detect cycle in a directed graph
    public boolean isCyclic(int V, List<List<Integer>> adj) {

        boolean[] vis = new boolean[V];
        boolean[] pathVis = new boolean[V];

        for (int u = 0; u < V; u++) {
            if (!vis[u]) {
                if (dfs(u, adj, vis, pathVis)) return true;
            }
        }
        return false;
    }
}

// ===============================================================

class Solution {
  public:
    bool dfs(int u, vector<vector<int>> adj, vector<bool> &vis, vector<bool> &pathVis) {
        vis[u] = true;
        pathVis[u] = true;
        for(auto &v : adj[u]) {
            if(pathVis[v]) return true;
            if(vis[v]) continue;
            if(dfs(v, adj, vis, pathVis)) return true;
        }
        pathVis[u] = false;
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<bool> vis(V, false), pathVis(V, false);
        for(int u = 0; u < V; u++) {
            if(!vis[u] && dfs(u, adj, vis, pathVis)) return true;
        }
        
        return false;
    }
};

// T : O(V + 2*E)
// S : O(V)
