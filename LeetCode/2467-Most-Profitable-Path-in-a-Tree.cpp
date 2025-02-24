// 2467. Most Profitable Path in a Tree

class Solution {
public:
    void get_height(int u, int par, int h, vector<vector<int>>& adj, int& bob, int& bob_height, vector<int>& prev) {
        if(u == bob) bob_height = h;
        prev[u] = par;
        for(auto &v : adj[u]) {
            if(v == par) continue;
            get_height(v, u, h + 1, adj, bob, bob_height, prev);
        }
    }

    void rec(int u, int par, vector<vector<int>>& adj, vector<int>& amount, int& curr, int& ans) {
        curr += amount[u];
        for(auto &v : adj[u]) {
            if(v == par) continue;
            rec(v, u, adj, amount, curr, ans);
        }
        if(adj[u].size() == 1 && adj[u][0] == par) ans = max(ans, curr);
        curr -= amount[u];
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> prev(n);
        int bob_height;
        get_height(0, 0, 1, adj, bob, bob_height, prev);

        for(int i = 0; i < (bob_height / 2); i++) {
            amount[bob] = 0;
            bob = prev[bob];
        }

        if(bob_height & 1) amount[bob] /= 2;

        int ans = INT_MIN, curr = 0;
        rec(0, 0, adj, amount, curr, ans);

        return ans;
    }
};
