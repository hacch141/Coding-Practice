// 886. Possible Bipartition

class Solution {
public:
    bool dfs(int u, int par, vector<vector<int>>& adj, vector<int>& col) {
        for(auto &v : adj[u]) {
            if(col[v] != -1) {
                if(col[u] == col[v]) return false;
            }
            else {
                col[v] = 1 - col[u];
                if(!dfs(v, u, adj, col)) return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for(auto &it : dislikes) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> col(n + 1, -1);
        for(int i = 1; i <= n; i++) {
            if(col[i] == -1) {
                col[i] = 0;
                if(!dfs(i, -1, adj, col)) return false;
            }
        }

        return true;
    }
};

//==================================================================

class Solution {
public:
    bool bfs(int node, vector<vector<int>>& adj, vector<int>& col) {
        queue<int> q;
        q.push(node);
        col[node] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto &v : adj[u]) {
                if(col[v] != -1) {
                    if(col[u] == col[v]) return false;
                }
                else {
                    col[v] = 1 - col[u];
                    q.push(v);
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for(auto &it : dislikes) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> col(n + 1, -1);
        for(int i = 1; i <= n; i++) {
            if(col[i] == -1) {
                if(!bfs(i, adj, col)) return false;
            }
        }

        return true;
    }
};
