// 1443. Minimum Time to Collect All Apples in a Tree

class Solution {

private:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& hasApple) {
        int time = 0;
        int childTime = 0;
        for(auto child : adj[node]) {
            if(child == parent) {
                continue;
            }
            childTime = dfs(child,node,adj,hasApple);
            if(childTime || hasApple[child]) {
                time += 2+childTime;
            }
        }
        return time;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(0,-1,adj,hasApple);
    }
};
