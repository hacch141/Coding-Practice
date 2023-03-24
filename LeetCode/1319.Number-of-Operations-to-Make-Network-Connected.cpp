// 1319. Number of Operations to Make Network Connected

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
