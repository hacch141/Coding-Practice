// 2493. Divide Nodes Into the Maximum Number of Groups

class Solution {
public:

    bool bipartite(int n, vector<vector<int>>& adj) {
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                color[i] = 0;
                queue<int> q;
                q.push(i);
                while(!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for(auto &v : adj[u]) {
                        if(color[v] != -1) {
                            if(color[v] == color[u]) return false;
                        }
                        else {
                            color[v] = 1 - color[u];
                            q.push(v);
                        }
                    }
                }
            }
        }
        return true;
    }

    int bfs(int node, int& n, vector<vector<int>>& adj) {
        vector<bool> vis(n, false);
        vis[node] = true;

        queue<int> q;
        q.push(node);

        int cnt = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int u = q.front();
                q.pop();
                for(auto &v : adj[u]) {
                    if(!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
            cnt++;
        }

        return cnt;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            adj[it[0] - 1].push_back(it[1] - 1);
            adj[it[1] - 1].push_back(it[0] - 1);
        }

        if(!bipartite(n, adj)) return -1;

        int ans = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            vector<int> cmp;
            if(!vis[i]) {
                queue<int> q;
                q.push(i);
                vis[i] = true;
                while(!q.empty()) {
                    int u = q.front();
                    q.pop();
                    cmp.push_back(u);
                    for(auto &v : adj[u]) {
                        if(!vis[v]) {
                            vis[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
            int mx = 0;
            for(auto u : cmp) {
                mx = max(mx, bfs(u, n, adj));
            }
            ans += mx;
        }

        return ans;
    }
};
