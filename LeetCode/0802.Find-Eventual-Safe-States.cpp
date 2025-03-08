// 802. Find Eventual Safe States

class Solution {
public:
    bool dfs(int u, vector<bool>& vis, vector<bool>& pathvis, vector<vector<int>>& graph) {
        vis[u] = true;
        pathvis[u] = true;
        for(auto &v : graph[u]) {
            if(pathvis[v]) return true;
            if(!vis[v] && dfs(v, vis, pathvis, graph)) return true;
        }
        pathvis[u] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> vis(n, false), pathvis(n, false);
        for(int u = 0; u < n; u++) {
            if(!vis[u]) {
                dfs(u, vis, pathvis, graph);
            }
        }

        vector<int> ans;
        for(int u = 0; u < n; u++) {
            if(!pathvis[u]) ans.push_back(u);
        }

        return ans;
    }
};



class Solution {
public:

    bool dfs(int u, vector<bool>& vis, vector<bool>& pathvis, vector<bool>& safe, vector<vector<int>>& graph) {
        if(vis[u]) return safe[u];
        
        vis[u] = true;
        pathvis[u] = true;
        for(auto &v : graph[u]) {
            if(pathvis[v]) return safe[u] = false;
            if(vis[v] && !safe[v]) return safe[v];
            if(!dfs(v, vis, pathvis, safe, graph)) return safe[u] = false;
        }
        pathvis[u] = false;
        return safe[u];
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> vis(n, false), pathvis(n, false), safe(n, true);
        for(int u = 0; u < n; u++) {
            if(!vis[u]) {
                dfs(u, vis, pathvis, safe, graph);
            }
        }

        vector<int> ans;
        for(int u = 0; u < n; u++) {
            if(safe[u]) ans.push_back(u);
        }

        return ans;
    }
};

// =======================================================================================

class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& path_vis, vector<bool>& safe) {
        vis[u] = true;
        path_vis[u] = true;
        for(auto &v : adj[u]) {
            if(!vis[v] && !dfs(v, adj, vis, path_vis, safe)) {
                safe[u] = false;
            }
            else if(!safe[v] || path_vis[v]) {
                safe[u] = false;
            }
        }
        path_vis[u] = false;
        return safe[u];
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false), path_vis(n, false), safe(n, true);
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i, graph, vis, path_vis, safe);
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};
