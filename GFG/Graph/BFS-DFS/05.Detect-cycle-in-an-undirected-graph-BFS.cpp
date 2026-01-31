// Detect cycle in an undirected graph

import java.util.*;

class Solution {

    private boolean bfs(int src, int parent, List<List<Integer>> adj, boolean[] vis) {
        Queue<int[]> q = new LinkedList<>();
        vis[src] = true;
        q.offer(new int[]{src, parent});

        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int u = curr[0];
            int par = curr[1];

            for (int v : adj.get(u)) {
                if (v == par) continue;

                if (vis[v]) return true;   // cycle found

                vis[v] = true;
                q.offer(new int[]{v, u});
            }
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    public boolean isCycle(List<List<Integer>> adj) {
        int n = adj.size();
        boolean[] vis = new boolean[n];

        for (int u = 0; u < n; u++) {
            if (!vis[u]) {
                if (bfs(u, -1, adj, vis)) return true;
            }
        }
        return false;
    }
}


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
