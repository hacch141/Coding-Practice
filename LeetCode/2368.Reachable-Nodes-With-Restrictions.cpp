// 2368. Reachable Nodes With Restrictions

class Solution {
public:

    void dfs(int start, vector<int>& vis, vector<vector<int>>& adj, int& cnt) {
        vis[start] = 1;
        cnt++;

        for(auto i : adj[start]) {
            if(!vis[i]) {
                dfs(i,vis,adj,cnt);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        for(auto i : restricted) vis[i]=1;

        int cnt = 0;
        dfs(0,vis,adj,cnt);

        return cnt;
    }
};
