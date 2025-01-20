// 1319. Number of Operations to Make Network Connected

// BFS
class Solution {
public:

    void bfs(int start, vector<int>& vis, vector<vector<int>>& adj) {
        vis[start] = 1;
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto i : adj[curr]) {
                if(!vis[i]) {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        vector<vector<int>> adj(n);
        for(auto i : connections) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(n,0);
        int cnt = 0;

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                cnt++;
                bfs(i,vis,adj);
            }
        }
        
        return cnt-1;
    }
};

// DFS
class Solution {
public:

    void dfs(int start, vector<int>& vis, vector<vector<int>>& adj) {
        vis[start] = 1;
        for(auto i : adj[start]) {
            if(!vis[i]) {
                dfs(i,vis,adj);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto i : connections) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(n,0);
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i,vis,adj);
            }
        }

        if(connections.size() < n-1) return -1;
        return cnt-1;
    }
};

// DSU-1
class DisjointSet {
private:
    vector<int> parent, rank;
public:
    DisjointSet(int n ) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;

        DisjointSet ds(n);
        int cnt_comp = n;
        for(auto &con : connections) {
            int u = con[0];
            int v = con[1];
            if(ds.find_par(u) != ds.find_par(v)) {
                ds.union_by_rank(u, v);
                cnt_comp--;
            }
        }

        return cnt_comp - 1;
    }
};

// DSU-2
class DisjointSet {
private:
    vector<int> parent, rank;
public:
    DisjointSet(int n ) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra_con = 0;
        for(auto &con : connections) {
            int u = con[0];
            int v = con[1];
            if(ds.find_par(u) == ds.find_par(v)) {
                extra_con++;
            }
            else {
                ds.union_by_rank(u, v);
            }
        }

        set<int> st;
        for(int u = 0; u < n; u++) {
            st.insert(ds.find_par(u));
        }

        return extra_con >= st.size() - 1 ? st.size() - 1 : -1;
    }
};
