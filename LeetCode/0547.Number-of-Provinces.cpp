// 547. Number of Provinces


// BFS
class Solution {
public:

    void bfs(int start, vector<int>& vis, vector<vector<int>>& adj) {
        vis[start] = 1;
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto v : adj[u]) {
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i!=j && isConnected[i][j]==1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans = 0;
        vector<int> vis(n,0);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                bfs(i,vis,adj);
                ans++;
            }
        }

        return ans;
    }
};


// DFS
class Solution {
public:

    void dfs(int u, vector<int>& vis, vector<vector<int>>& adj) {
        vis[u] = 1;
        for(auto v : adj[u]) {
            if(!vis[v]) {
                dfs(v,vis,adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i!=j && isConnected[i][j]==1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans = 0;
        vector<int> vis(n,0);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i,vis,adj);
                ans++;
            }
        }

        return ans;
    }
};
