// 802. Find Eventual Safe States

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
