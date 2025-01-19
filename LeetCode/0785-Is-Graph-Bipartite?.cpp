// 785. Is Graph Bipartite?

// DFS
class Solution {
public:
    bool dfs(int u, int curr_color, vector<vector<int>>& adj, vector<bool> &vis, vector<int> &color) {
        vis[u] = true;
        color[u] = curr_color;
        for(auto &v : adj[u]) {
            if(vis[v] && color[v] == curr_color) return false;
            if(!vis[v]) {
                if(!dfs(v, 1 - curr_color, adj, vis, color)) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> vis(n, false);
        vector<int> color(n, 0);
        for(int u = 0; u < n; u++) {
            if(!vis[u]) {
                if(!dfs(u, 0, graph, vis, color)) return false;
            }
        }

        return true;
    }
};

// BFS
class Solution {
public:
    bool dfs(int st, vector<vector<int>>& adj, vector<bool> &vis, vector<int> &color) {
        vis[st] = true;
        queue<pair<int,int>> q;
        q.push({st, 0});
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int u = curr.first, curr_color = curr.second;
            for(auto &v : adj[u]) {
                if(vis[v] && color[v] == curr_color) return false;
                if(!vis[v]) {
                    vis[v] = true;
                    color[v] = 1 - curr_color;
                    q.push({v, 1 - curr_color});
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> vis(n, false);
        vector<int> color(n, 0);
        for(int u = 0; u < n; u++) {
            if(!vis[u]) {
                if(!dfs(u, graph, vis, color)) return false;
            }
        }

        return true;
    }
};
