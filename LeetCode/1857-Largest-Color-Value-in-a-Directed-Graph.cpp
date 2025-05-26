// 1857. Largest Color Value in a Directed Graph

// dfs
class Solution {
public:
    int dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& path_vis, string& colors, vector<vector<int>>& dp) {
        vis[u] = true;
        path_vis[u] = true;
        dp[u][colors[u] - 'a'] = 1;
        for(auto &v : adj[u]) {
            if(path_vis[v]) {
                return -1;
            }
            else if(!vis[v]) {
                if(dfs(v, adj, vis, path_vis, colors, dp) == -1) return -1;
            }
            for (int i = 0; i < 26; i++) {
                dp[u][i] = max(dp[u][i], dp[v][i] + ((colors[u] - 'a') == i));
            }
        }
        path_vis[u] = false;
        return *max_element(dp[u].begin(), dp[u].end());
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
        }

        int ans = 0;
        vector<bool> vis(n, false), path_vis(n, false);
        vector<vector<int>> dp(n, vector<int>(26, 0));

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int res = dfs(i, adj, vis, path_vis, colors, dp);
                if(res == -1) return -1;
                ans = max(ans, res);
            }
        }

        return max(1, ans);
    }
};

// bfs (topological)
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(26, 0));

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                dp[i][colors[i] - 'a']++;
            }
        }

        int cnt_nodes = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            cnt_nodes++;
            ans = max(ans, *max_element(dp[u].begin(), dp[u].end()));
            for(auto &v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
                for(int i = 0; i < 26; i++) {
                    dp[v][i] = max(dp[v][i], dp[u][i] + (colors[v] - 'a' == i));
                }
            }
        }

        return cnt_nodes != n ? -1 :  ans;
    }
};
