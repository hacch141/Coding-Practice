// Cheapest Flights Within K Stops

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<vector<pair<int,int>>> adj(n);
        for(auto i: flights) {
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        vector<int> cost(n,1e9);
        cost[src] = 0;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        
        while(!q.empty()) {
            auto it = q.front();
            int u = it.second.first;
            int c = it.second.second;
            int stops = it.first;
            q.pop();
            
            for(auto it : adj[u]) {
                int v = it.first;
                int w = it.second;
                if(w + c < cost[v] && stops<=K) {
                    cost[v] = w + c;
                    q.push({stops+1,{v,cost[v]}});
                }
            }
        }
        
        return cost[dst] != 1e9 ? cost[dst] : -1; 
    }
};

// T : O(V + 2*E)
// S : O(V + 2*E)
