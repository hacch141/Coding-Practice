// 3249. Count the Number of Good Nodes

class Solution {
public:

    int dfs(int u, int par, int& ans, vector<vector<int>>& adj) {
        if(adj[u].size() == 0) return 1;

        int prev = -1, sz = 1;
        bool f = true;
        for(auto v : adj[u]) {
            if(v == par) continue;
            int curr = dfs(v, u, ans, adj);
            sz += curr;
            if(prev == -1) {
                prev = curr;
            }
            else if(prev != curr) {
                f = false;
            }
        }
        if(f) ans++;
        return sz;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int ans = 0;
        dfs(0, 0, ans, adj);
        return ans;
    }
};
