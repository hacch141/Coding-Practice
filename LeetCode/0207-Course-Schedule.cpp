// 207. Course Schedule

// DFS
class Solution {
public:
    bool dfs(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &path_vis) {
        vis[u] = true;
        path_vis[u] = true;
        for(auto &v : adj[u]) {
            if(path_vis[v]) return true;
            if(vis[v]) continue;
            if(dfs(v, adj, vis, path_vis)) return true;
        }
        path_vis[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(numCourses, false), path_vis(numCourses, false);
        for(int u = 0; u < numCourses; u++) {
            if(!vis[numCourses]) {
                if(dfs(u, adj, vis, path_vis)) return false;
            }
        }

        return true;
    }
};

// BFS
class Solution {
public:
    bool bfs(int n, vector<vector<int>> &adj) {
        vector<int> indegree(n, 0);
        for(auto &u : adj) {
            for(auto &v : u) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for(int u = 0; u < n; u++) {
            if(indegree[u] == 0) {
                q.push(u);
            }
        }

        int cnt = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;
            for(auto &v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return cnt != n;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        
        if(bfs(numCourses, adj)) return false;
        
        return true;
    }
};
