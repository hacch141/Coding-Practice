// 839. Similar String Groups

// DFS
class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[u] = true;
        for(auto &v : adj[u]) {
            if(!vis[v]) dfs(v, adj, vis);
        }
    }

    bool is_similar(string& s1, string& s2) {
        int n = s1.length(), cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                cnt++;
            }
        }
        return cnt == 0 || cnt == 2;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> adj(n);
        for(int u = 0; u < n; u++) {
            for(int v = u + 1; v < n; v++) {
                if(is_similar(strs[u], strs[v])) {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }

        int cnt = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, adj, vis);
            }
        }

        return cnt;
    }
};

// BFS
class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        queue<int> q;
        q.push(node);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = true;
            for(auto &v : adj[u]) {
                if(!vis[v]) q.push(v);
            }
        }
    }

    bool is_similar(string& s1, string& s2) {
        int n = s1.length(), cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                cnt++;
            }
        }
        return cnt == 0 || cnt == 2;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> adj(n);
        for(int u = 0; u < n; u++) {
            for(int v = u + 1; v < n; v++) {
                if(is_similar(strs[u], strs[v])) {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }

        int cnt = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                cnt++;
                bfs(i, adj, vis);
            }
        }

        return cnt;
    }
};

// DisjointSet
class DisjointSet {
private:
    vector<int> parent, sz;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find_par(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find_par(parent[u]);
    }

    void union_by_size(int u, int v) {
        int par_u = find_par(u), par_v = find_par(v);
        if(par_u == par_v) {
            return;
        }
        else if(sz[par_u] > sz[par_v]) {
            sz[par_u] += sz[par_v];
            parent[par_v] = par_u;
        }
        else {
            sz[par_v] += sz[par_u];
            parent[par_u] = par_v;
        }
    }
};

class Solution {
public:
    bool is_similar(string& s1, string& s2) {
        int n = s1.length(), cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                cnt++;
            }
        }
        return cnt == 0 || cnt == 2;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> adj(n);
        DisjointSet ds(n);

        int cnt = n;
        for(int u = 0; u < n; u++) {
            for(int v = u + 1; v < n; v++) {
                if(is_similar(strs[u], strs[v]) && ds.find_par(u) != ds.find_par(v)) {
                    ds.union_by_size(u, v);
                    cnt--;
                }
            }
        }

        return cnt;
    }
};
