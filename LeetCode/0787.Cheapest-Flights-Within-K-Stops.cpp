// 787. Cheapest Flights Within K Stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, INT_MAX);
        queue<pair<int,int>> q;
        q.push({src, 0});
        dist[src] = 0;

        while(k >= 0 && !q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto it = q.front();
                q.pop();
                int u = it.first, d = it.second;
                for(auto &nei : adj[u]) {
                    int v = nei.first, new_d = d + nei.second;
                    if(new_d < dist[v]) {
                        dist[v] = new_d;
                        q.push({v, new_d});
                    }
                }
            }
            k--;
        }
        return dist[dst] != INT_MAX ? dist[dst] : -1;
    }
};
