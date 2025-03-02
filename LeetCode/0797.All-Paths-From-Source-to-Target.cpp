// 797. All Paths From Source to Target

class Solution {
public:
    void dfs(int u, int dest, vector<int>& curr, vector<vector<int>>& graph, vector<vector<int>>& ans) {
        curr.push_back(u);
        if(u == dest) {
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        for(auto &v : graph[u]) {
            dfs(v, dest, curr, graph, ans);
        }
        curr.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(0, n - 1, curr, graph, ans);
        return ans;
    }
};

// ===========================================================================

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;

        queue<pair<int,vector<int>>> q;
        q.push({0, {0}});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int u = it.first;
            vector<int> curr = it.second;
            if(u == n - 1) {
                ans.push_back(curr);
                continue;
            }
            for(auto &v : graph[u]) {
                curr.push_back(v);
                q.push({v, curr});
                curr.pop_back();
            }
        }
        
        return ans;
    }
};
