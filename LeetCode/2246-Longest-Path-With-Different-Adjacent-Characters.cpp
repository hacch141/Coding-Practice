// 2246. Longest Path With Different Adjacent Characters

class Solution {
public:
    int dfs(int u, int par, vector<vector<int>>& adj, string& s, int& ans) {
        int mx = 0, mx_2 = 0;
        for(auto &v : adj[u]) {
            if(v == par) continue;
            int len_child = dfs(v, u, adj, s, ans);
            if(s[u] != s[v]) {
                if(len_child > mx) {
                    mx_2 = mx;
                    mx = len_child;
                }
                else if(len_child > mx_2) {
                    mx_2 = len_child;
                }
            }
        }
        if(mx != 0 && mx_2 != 0) {
            ans = max(ans, 1 + mx + mx_2);
        }
        else if(mx != 0) {
            ans = max(ans, 1 + mx);
        }
        return mx + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int v = 1; v < n; v++) {
            int u = parent[v];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 1;
        dfs(0, -1, adj, s, ans);

        return ans;
    }
};
