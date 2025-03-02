// 1443. Minimum Time to Collect All Apples in a Tree

class Solution {
public:
    int dfs(int u, int par, vector<vector<int>>& adj, vector<bool>& hasApple) {
        int cnt = 0;
        for(auto &v : adj[u]) {
            if(v == par) continue;
            cnt += dfs(v, u, adj, hasApple);
        }
        cnt += (cnt > 0 || hasApple[u]);
        return cnt;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cnt = dfs(0, -1, adj, hasApple);
        return cnt > 0 ? (cnt - 1) * 2 : 0;
    }
};
