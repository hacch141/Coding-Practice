// 802. Find Eventual Safe States

class Solution {

private:
    bool dfs(int u, vector<int>& vis, vector<int>& pathvis, vector<vector<int>>& graph) {
        vis[u] = 1;
        pathvis[u] = 1;
        for(auto v : graph[u]) {
            if(!vis[v]) {
                if(dfs(v,vis,pathvis,graph)) {
                    return true;
                }
            }
            else if(pathvis[v]) {
                return true;
            }
        }
        pathvis[u] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i,vis,pathvis,graph);
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(pathvis[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
