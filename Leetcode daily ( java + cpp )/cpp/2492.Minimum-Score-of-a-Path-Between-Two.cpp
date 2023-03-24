// 2492. Minimum Score of a Path Between Two

class Solution {
public:

    void dfs(int start, vector<int>& vis, vector<vector<pair<int,int>>>& adj, vector<int>& ans) {
        vis[start] = 1;
        for(auto it : adj[start]) {
            if(!vis[it.first]) {
                ans.push_back(it.first);
                dfs(it.first,vis,adj,ans);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u-1].push_back({v-1,wt});
            adj[v-1].push_back({u-1,wt});
        }

        vector<int> vis(n,0);
        vector<int>ans;
        dfs(0,vis,adj,ans);

        int res = INT_MAX;
        for(int i=0 ; i<ans.size() ; i++){
            for(auto it : adj[ans[i]]){
                res = min(res,it.second);
            }
        }
        return res;
    }
};
