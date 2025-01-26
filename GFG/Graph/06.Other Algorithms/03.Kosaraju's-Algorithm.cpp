// Kosaraju's Algorithm

class Solution {
  public:
  
    void topo(int u, vector<vector<int>> &adj, vector<bool>& vis, stack<int>& st) {
        vis[u] = true;
        for(auto &v : adj[u]) {
            if(!vis[v]) topo(v, adj, vis, st);
        }
        st.push(u);
    }
    
    void dfs(int u, vector<vector<int>> &rev_adj, vector<bool>& vis) {
        vis[u] = true;
        for(auto &v : rev_adj[u]) {
            if(!vis[v]) dfs(v, rev_adj, vis);
        }
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<bool> vis(n, false);
        
        // Topo sort
        stack<int> st;
        for(int u = 0; u < n; u++) {
            if(!vis[u]) {
                topo(u, adj, vis, st);
            }
        }
        
        // Reverse Graph
        vector<vector<int>> rev_adj(n);
        for(int u = 0; u < n; u++) {
            for(auto &v : adj[u]) {
                rev_adj[v].push_back(u);
            }
        }
        
        // Call dfs and cnt components based on the topo order
        vis = vector<bool>(n, false);
        int cnt = 0;
        while(!st.empty()) {
            int u = st.top();
            st.pop();
            if(!vis[u]) {
                dfs(u, rev_adj, vis);
                cnt++;
            }
        }
        
        return cnt;
    }
};
