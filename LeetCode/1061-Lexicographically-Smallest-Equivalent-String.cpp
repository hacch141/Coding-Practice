// 1061. Lexicographically Smallest Equivalent String

class Solution {
public:
    void dfs(int u, int&  mn, vector<vector<int>>& adj, vector<int>& cmp_nodes, vector<int>& vis) {
        cmp_nodes.push_back(u);
        vis[u] = true;
        mn = min(mn, u);
        for(auto v : adj[u]) {
            if(!vis[v]) dfs(v, mn, adj, cmp_nodes, vis);
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();

        vector<vector<int>> adj(26);
        for(int i = 0; i < n; i++) {
            int u = s1[i] - 'a', v = s2[i] - 'a';
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int,int> mp;
        vector<int> vis(26, false);
        for(int i = 0; i < 26; i++) {
            vector<int> cmp_nodes;
            int mn = i;
            if(!vis[i]) dfs(i, mn, adj, cmp_nodes, vis);
            for(auto i : cmp_nodes) mp[i] = mn;
        }

        string ans = baseStr;
        for(auto &ch : ans) ch = mp[ch - 'a'] + 'a';

        return ans;
    }
};
