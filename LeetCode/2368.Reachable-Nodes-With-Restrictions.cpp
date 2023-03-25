// 2368. Reachable Nodes With Restrictions

class Solution {
public:

    void dfs(int start, vector<int>& vis, vector<vector<int>>& adj, unordered_map<int,int>& mp, int& cnt) {
        vis[start] = 1;
        cnt++;

        for(auto i : adj[start]) {
            if(!vis[i] && mp.find(i)==mp.end()) {
                dfs(i,vis,adj,mp,cnt);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        unordered_map<int,int> mp;
        
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        for(auto i : restricted) mp[i]++;

        int cnt = 0;
        dfs(0,vis,adj,mp,cnt);

        return cnt;
    }
};
