// 2492. Minimum Score of a Path Between Two

class Solution {
public:
    void dfs(int u, vector<vector<pair<int,int>>>& adj, vector<bool>& vis, int& ans) {
        vis[u] = true;
        for(auto &it : adj[u]) {
            int v = it.first;
            ans = min(ans, it.second);
            if(!vis[v]) dfs(v, adj, vis, ans);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int ans = INT_MAX;
        vector<bool> vis(n + 1, false);
        dfs(1, adj, vis, ans);

        return ans;
    }
};

// =====================================================================

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int ans = INT_MAX;
        vector<bool> vis(n + 1, false);
        queue<int> q;
        q.push(1);

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int u = q.front();
                q.pop();
                vis[u] = true;
                for(auto &it : adj[u]) {
                    int v = it.first;
                    ans = min(ans, it.second);
                    if(!vis[v]) q.push(v);
                }
            }
        }

        return ans;
    }
};
