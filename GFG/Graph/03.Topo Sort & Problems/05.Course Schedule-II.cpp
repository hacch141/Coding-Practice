// Course Schedule - II

// BFS
class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int> ans;
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        
        for(auto i : prerequisites) {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int cnt = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;
            ans.push_back(u);
            for(auto v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if(cnt != n) return {};
        return ans;
    }
};

// T : O(V + 2*E)
// S : O(V)


// DFS
class Solution
{
    
  private:
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathvis, vector<int>& ans) {
        vis[u] = 1;
        pathvis[u] = 1;
        for(auto v : adj[u]) {
            if(!vis[v]) {
                if(dfs(v,adj,vis,pathvis,ans) == false) return false;
            }
            else if(pathvis[v]){
                return false;
            }
        }
        
        ans.push_back(u);
        pathvis[u] = 0;
        return true;
    }
    
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int> ans;
        vector<vector<int>> adj(n);
        
        for(auto i : prerequisites) {
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(dfs(i,adj,vis,pathvis,ans) == false) return {};
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// T : O(V + 2*E)
// S : O(V)
