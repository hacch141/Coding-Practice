// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph

// DFS
class Solution {
public:

    long long dfs(int u, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[u] = 1;
        long long comp_nodes = 1;
        for(auto &v : adj[u]) {
            if(!vis[v]) {
                comp_nodes += dfs(v, adj, vis);
            }
        }
        return comp_nodes;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        long long ans = 0, total_nodes = 0;
        vector<bool> vis(n, false);
        for(int u = 0; u < n; u++) {
            if(!vis[u]) {
                int comp_nodes = dfs(u, adj, vis);
                ans += comp_nodes * total_nodes;
                total_nodes += comp_nodes;
            }
        }

        return ans;
    }
};

// BFS
class Solution {
public:
    long long bfs(int st, vector<vector<int>> &adj, vector<bool> &vis) {
        queue<int> q;
        q.push(st);
        vis[st] = 1;
        long long comp_nodes = 1;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto &v : adj[u]) {
                if(!vis[v]) {
                    vis[v] = true;
                    comp_nodes++;
                    q.push(v);
                }
            }
        }
        return comp_nodes;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        long long ans = 0, total_nodes = 0;
        vector<bool> vis(n, false);
        for(int u = 0; u < n; u++) {
            if(!vis[u]) {
                int comp_nodes = bfs(u, adj, vis);
                ans += comp_nodes * total_nodes;
                total_nodes += comp_nodes;
            }
        }

        return ans;
    }
};

// DSU
class DisjointSet {
private:
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find_par(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find_par(parent[u]);
    }

    void union_by_rank(int u, int v) {
        int par_u = find_par(u);
        int par_v = find_par(v);
        if(par_u == par_v) {
            return;
        }
        else if(rank[par_u] > rank[par_v]) {
            parent[par_v] = par_u;
        }
        else if(rank[par_u] < rank[par_v]) {
            parent[par_u] = par_v;
        }
        else {
            parent[par_v] = par_u;
            rank[par_u]++;
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(auto &it : edges) {
            ds.union_by_rank(it[0], it[1]);
        }

        vector<int> comp_nodes(n, 0);
        for(int u = 0; u < n; u++) {
            comp_nodes[ds.find_par(u)]++;
        }

        long long total_pairs = 0;
        int total_nodes = 0;
        for(int u = 0; u < n; u++) {
            total_pairs += 1LL * total_nodes * comp_nodes[u];
            total_nodes += comp_nodes[u];
        }

        return total_pairs;
    }
};
