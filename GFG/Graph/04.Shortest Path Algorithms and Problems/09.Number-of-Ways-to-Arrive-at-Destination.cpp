// Number of Ways to Arrive at Destination

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<vector<pair<int,int>>> adj(n);
        for(auto i : roads) {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        vector<int> ways(n,0);
        vector<long> dist(n,INT_MAX);
        dist[0] = 0;
        ways[0] = 1;
        int mod = 1e9 + 7;
        
        while(!pq.empty()) {
            int u = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            for(auto it : adj[u]) {
                int v = it.first;
                int w = it.second;
                if(dis + w < dist[v]) {
                    dist[v] = dis + w;
                    ways[v] = ways[u];
                    pq.push({dist[v],v});
                }
                else if((dis + w)%mod == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }
        
        return ways[n-1];
    }
};

// T : O(E * LogV)
// S : O(n)
