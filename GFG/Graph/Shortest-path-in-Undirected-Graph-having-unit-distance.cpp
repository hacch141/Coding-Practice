// Shortest path in Undirected Graph having unit distance

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        for(int i=0; i<M; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> ans(N);
        for(int i=0; i<N; i++) {
            ans[i] = 1e9;
        }
        ans[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto it : adj[u]) {
                if(ans[u]+1 < ans[it]) {
                    ans[it] = ans[u]+1;
                    q.push(it);
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
