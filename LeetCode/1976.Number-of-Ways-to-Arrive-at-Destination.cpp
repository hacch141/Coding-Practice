// 1976. Number of Ways to Arrive at Destination

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for(auto it : roads) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue< pair<long long,long long>, vector< pair<long long,long long> >, greater< pair<long long,long long> > > pq;
        pq.push({0,0});
        vector<long long> dist(n,LONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        int mod = (int)(1e9+7);

        while(!pq.empty()) {
            long long d = pq.top().first;
            long long u = pq.top().second;
            pq.pop();

            if(d > dist[u]) continue;

            for(auto it : adj[u]) {
                long long v = it.first;
                long long weight = it.second;
                if(d+weight<dist[v]) {
                    dist[v] = d + weight;
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
