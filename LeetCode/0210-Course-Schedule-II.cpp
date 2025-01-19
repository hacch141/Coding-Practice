// 210. Course Schedule II

// DFS
class Solution {
public:
    bool dfs(int u, vector<vector<int>> &adj, vector<int> &topo, vector<bool> &vis, vector<bool> &path_vis) {
        vis[u] = true;
        path_vis[u] = true;
        for(auto &v : adj[u]) {
            if(path_vis[v]) return true;
            if(vis[v]) continue;
            if(dfs(v, adj, topo, vis, path_vis)) return true;
        }
        path_vis[u] = false;
        topo.push_back(u);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(numCourses, false), path_vis(numCourses, false);
        vector<int> topo;
        for(int u = 0; u < numCourses; u++) {
            if(!vis[u] && dfs(u, adj, topo, vis, path_vis)) {
                return {};
            }
        }

        reverse(topo.begin(), topo.end());
        return topo;
    }
};

// BFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(numCourses, 0);
        for(auto &u : adj) {
            for(auto &v : u) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for(int u = 0; u < numCourses; u++) {
            if(indegree[u] == 0) {
                q.push(u);
            }
        }

        vector<int> topo;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for(auto &v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if(topo.size() == numCourses) return topo;
        return {};
    }
};
