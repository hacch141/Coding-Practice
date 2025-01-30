// 2493. Divide Nodes Into the Maximum Number of Groups

class Solution {
public:

    bool is_odd_len_cycle(int n, vector<vector<int>> &adj) {
        vector<int> color(n + 1, -1);
        
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;
                
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    
                    for (int v : adj[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return true; // Odd-length cycle detected
                        }
                    }
                }
            }
        }
        return false;
    }

    int bfs(int start, vector<vector<int>>& adj) {
        queue<int> q;
        vector<int> dist(adj.size(), -1);
        q.push(start);
        dist[start] = 0;
        int maxDist = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    maxDist = max(maxDist, dist[v]);
                    q.push(v);
                }
            }
        }
        return maxDist + 1;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        if (is_odd_len_cycle(n, adj)) return -1;

        vector<bool> vis(n + 1, false);
        int totalMax = 0;

        for (int u = 1; u <= n; u++) {
            if (!vis[u]) {
                vector<int> component;
                queue<int> q;
                q.push(u);
                vis[u] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);

                    for (int v : adj[node]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                }

                int maxDist = 0;
                for (int start : component) {
                    maxDist = max(maxDist, bfs(start, adj));
                }
                totalMax += maxDist;
            }
        }
        return totalMax;
    }
};

