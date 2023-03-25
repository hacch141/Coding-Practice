// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph

class Solution {
public:

    void dfs(int start, vector<int>& vis, vector<vector<int>>& adj, int& nodes) {
        vis[start] = 1;
        nodes++;
        for(auto i : adj[start]) {
            if(!vis[i]) {
                dfs(i,vis,adj,nodes);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(n,0);
        long long ans = 0;
        int curr_total = 0;

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                vis[i] = 1;
                int nodes = 0;
                dfs(i,vis,adj,nodes);
                ans += (long long)nodes*curr_total;
                curr_total += nodes;
            }
        }

        return ans;
    }
};
