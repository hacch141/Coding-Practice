// DFS of Graph

class Solution {

  private: 
  void dfs(int start, vector<int> &ans, int vis[], vector<int> adj[]) {
      vis[start] = 1;
      ans.push_back(start);
      for(auto it : adj[start]) {
          if(!vis[it]) {
              dfs(it, ans, vis, adj);
          }
      }
  }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        vector<int> ans;
        int start = 0;
        dfs(start, ans, vis, adj) ;
        return ans;
    }
};

// T : O (V + 2*E)
// S : O (V)
