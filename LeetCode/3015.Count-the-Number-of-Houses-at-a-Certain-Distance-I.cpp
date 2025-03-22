// 3015. Count the Number of Houses at a Certain Distance I

class Solution {
public:
    void bfs(int start, int n, vector<vector<int>>& adj, vector<int>& ans) {

        queue<int> q;
        q.push(start);

        vector<bool> vis(n, false);
        vis[start] = true;

        int dist = 0;
        while(!q.empty()) {
            int sz = q.size();
            if(dist > 0) ans[dist - 1] += sz;
            while(sz--) {
                int u = q.front();
                q.pop();
                for(auto &v : adj[u]) {
                    if(!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            dist++;
        }
    }

    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }

        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);

        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            bfs(i, n, adj, ans);
        }

        return ans;
    }
};

// ================================================================

class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adj(n, vector<int>(n, 1e9));
        for(int i = 0; i < n - 1; i++) {
            adj[i][i + 1] = 1;
            adj[i + 1][i] = 1;
        }

        for(int i = 0; i < n; i++) adj[i][i] = 0;

        adj[x - 1][y - 1] = 1;
        adj[y - 1][x - 1] = 1;

        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }

        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j || adj[i][j] == 1e9) continue;
                ans[adj[i][j] - 1]++;
            }
        }

        return ans;
    }
};
