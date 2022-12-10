// Shortest path in Directed Acyclic Graph

class Solution {
    
  private:
     void topoSort(int node, stack<int> &st, int vis[], vector<pair<int,int>> adj[]) {
         vis[node] = 1;
         for(auto it : adj[node]) {
             int v = it.first;
             if(!vis[v]) {
                 topoSort(v, st, vis, adj);
             }
         }
         st.push(node);
     }
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(int i=0; i<M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        int vis[N] = {0};
        stack<int> st;
        for(int i=0; i<N; i++) {
            if(!vis[i]) {
                topoSort(i, st, vis, adj);
            }
        }
        
        vector<int> ans(N);
        for(int i=0; i<N; i++) {
            ans[i] = 1e9;
        }
        ans[0] = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            for(auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if(ans[node]+wt < ans[v]) {
                    ans[v] = ans[node]+wt;
                }
            }
        }
        for(int i=0; i<N; i++) {
            if(ans[i] == 1e9) {
                ans[i] = -1;
            }
        }
        return ans;
    }
};
