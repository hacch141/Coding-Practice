class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(auto it : edges) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,1});
        vector<int> dist(n+1,1e9);
        vector<int> parent(n+1);
        for(int i=0; i<n+1; i++) parent[i] = i;
        dist[1] = 0;
        
        while(!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            for(auto it : adj[u]) {
                int v = it.first;
                int weight = it.second;
                if(d+weight < dist[v]) {
                    dist[v] = d+weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        if(dist[n] == 1e9) return {-1};
        vector<int> ans;
        int node = n;
        while(parent[node] != node) {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
