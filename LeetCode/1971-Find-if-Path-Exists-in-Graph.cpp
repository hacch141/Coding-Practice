// 1971. Find if Path Exists in Graph

class Solution {
public:

    bool dfs(int u, int dest, vector<vector<int>>& adj, vector<bool>& vis) {
        if(u == dest) return true;
        vis[u] = true;
        for(auto v : adj[u]) {
            if(!vis[v]) {
                if(dfs(v, dest, adj, vis)) return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n, false);
        return dfs(source, destination, adj, vis);
    }
};
