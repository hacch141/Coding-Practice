// 3067. Count Pairs of Connectable Servers in a Weighted Tree Network

class Solution {
public:
    
    vector<pair<int,int>> adj[1005];
    int spd;
    
    int dfs(int u, int par, int w) {
        int ans = 0;
        for(auto i : adj[u]) {
            int v = i.first;
            int wg = i.second;
            if(v == par) continue;
            ans += dfs(v, u, w + wg);
        }
        return ans + ((w % spd) == 0);
    }
    
    int solve(int u) {
        int ans = 0;
        vector<int> vec;
        for(auto i : adj[u]) {
            int v = i.first;
            int w = i.second;
            vec.push_back(dfs(v, u, w));
        }
        int len = vec.size();
        for(int i = 0; i < len; i++) {
            for(int j = i + 1; j < len; j++) {
                ans += vec[i] * vec[j];
            }
        }
        return ans;
    }
    
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size();
        spd = signalSpeed;
        for(int i = 0; i <= n; i++) adj[i].clear();
        for(auto i : edges) {
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> ans;
        for(int i = 0; i <= n; i++) {
            ans.push_back(solve(i));
        }
        return ans;
    }
};
