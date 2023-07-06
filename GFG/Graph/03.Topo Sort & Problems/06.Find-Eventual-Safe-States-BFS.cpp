// Eventual Safe States

// BFS
class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree(V,0);
        vector<int> adjRev[V];
        
        for(int u=0; u<V; u++) {
            for(auto v : adj[u]) {
                adjRev[v].push_back(u);
                indegree[u]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(auto v : adjRev[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};


// T : O(V + 2*E)
// S : O(O(VlogV + E)


// DFS
class Solution {
    
  private:
    bool dfs(int u, vector<int> adj[], vector<int>& vis, vector<int>& pathvis, vector<int>& safe) {
        vis[u] = 1;
        pathvis[u] = 1;
        
        for(auto v: adj[u]) {
            if(!vis[v]) {
                if(dfs(v,adj,vis,pathvis,safe) == false) return false;
            }
            else if(pathvis[v]) {
                return false;
            }
        }
        
        pathvis[u] = 0;
        safe[u] = 1;
        return true;
    }
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        vector<int> safe(V,0);
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(i,adj,vis,pathvis,safe);
            }
        }
        
        vector<int> ans;
        for(int i=0; i<V; i++) {
            if(safe[i]) ans.push_back(i);
        }
        
        return ans;
    }
};

// T : O(V + 2*E)
// S : O(V)
