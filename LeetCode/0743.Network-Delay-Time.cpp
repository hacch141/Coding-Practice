// 743. Network Delay Time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto &it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int u = curr.second, w = curr.first;
            for(auto it : adj[u]) {
                int v = it.first, nw = it.second;
                if(w + nw < dist[v]) {
                    dist[v] = w + nw;
                    pq.push({dist[v], v});
                }
            }
        }

        int mn_time = 0;
        for(int u = 1; u <= n; u++) {
            mn_time = max(mn_time, dist[u]);
        }

        return mn_time != INT_MAX ? mn_time : -1;
    }
};
