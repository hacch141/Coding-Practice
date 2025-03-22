// 1743. Restore the Array From Adjacent Pairs

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        map<int,vector<int>> adj;
        for(auto &it : adjacentPairs) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> ans;
        set<int> vis;
        for(auto &it : adjacentPairs) {
            int u = it[0], v = it[1];
            if(adj[u].size() == 1) {
                ans.push_back(u);
                vis.insert(u);
                break;
            }
            if(adj[v].size() == 1) {
                ans.push_back(v);
                vis.insert(v);
                break;
            }
        }

        while(ans.size() < n) {
            int u = ans.back();
            for(auto &v : adj[u]) {
                if(!vis.count(v)) {
                    vis.insert(v);
                    ans.push_back(v);
                }
            }
        }

        return ans;
    }
};
