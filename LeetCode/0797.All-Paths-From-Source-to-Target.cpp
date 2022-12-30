// 797. All Paths From Source to Target

class Solution {

private: 
    void dfs(int start, int end, vector<vector<int>>& graph, vector<int> &v, vector<vector<int>> &ans) {
        v.push_back(start);
        if(start==end) {
            ans.push_back(v);
        } else {
            for(auto it : graph[start]) {
                dfs(it,end,graph,v,ans);
            }
        }
        v.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> v;
        dfs(0,n-1,graph,v,ans);
        return ans;
    }
};
