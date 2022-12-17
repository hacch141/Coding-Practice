class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int,int>> adj[n];
        for(auto it : roads) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
        pq.push({0,0});
        vector<int> dist(n,1e9);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        int mod = (int)(1e9+7);
        
        while(!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            for(auto it : adj[u]) {
                int v = it.first;
                int weight = it.second;
                
                if(d+weight < dist[v]) {
                    dist[v] = d+weight;
                    ways[v] = ways[u];
                    pq.push({dist[v],v});
                }
                else if(d+weight == dist[v]) {
                    ways[v] = (ways[v]+ways[u])%mod;
                }
            }
        }
        return (ways[n-1])%mod;
    }
};
