// 1061. Lexicographically Smallest Equivalent String

class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& cmp, int& mn) {
        vis[u] = true;
        cmp.push_back(u);
        mn = min(mn, u);
        for(auto &v : adj[u]) {
            if(!vis[v]) {
                dfs(v, adj, vis, cmp, mn);
            }
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<int>> adj(26);
        int n = s1.length();
        for(int i = 0; i < n; i++) {
            adj[s1[i] - 'a'].push_back(s2[i] - 'a');
            adj[s2[i] - 'a'].push_back(s1[i] - 'a');
        }

        vector<int> lex(26);
        for(int i = 0; i < 26; i++) lex[i] = i;

        vector<bool> vis(26, false);
        for(int i = 0; i < 26; i++) {
            int mn = i;
            vector<int> cmp;
            if(!vis[i]) dfs(i, adj, vis, cmp, mn);
            for(auto &i : cmp) lex[i] = mn;
        }

        string ans;
        for(auto &ch : baseStr) {
            ans += (lex[ch - 'a'] + 'a');
        }

        return ans;
    }
};
