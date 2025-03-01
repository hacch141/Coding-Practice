// 1971. Find if Path Exists in Graph

class Solution {
public:

    bool dfs(int u, int dest, vector<vector<int>>& adj, vector<bool>& vis) {
        if(u == dest) return true;
        vis[u] = true;
        for(auto v : adj[u]) {
            if(!vis[v]) {
                if(dfs(v, dest, adj, vis)) return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n, false);
        return dfs(source, destination, adj, vis);
    }
};


// =================================================================================

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<int> q;
        q.push(source);
        vector<bool> vis(n, false);
        vis[source] = true;

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int u = q.front();
                q.pop();
                if(u == destination) return true;
                for(auto &v : adj[u]) {
                    if(!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }

        return false;
    }
};
