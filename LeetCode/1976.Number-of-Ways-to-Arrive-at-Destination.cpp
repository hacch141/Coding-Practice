// 1976. Number of Ways to Arrive at Destination

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0, 0});

        vector<long long> dist(n, LLONG_MAX), cnt(n, 0);
        dist[0] = 0;
        cnt[0] = 1;

        long long MOD = 1e9 + 7;

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            long long d = curr.first;
            long long u = curr.second;
            for(auto &it : adj[u]) {
                int v = it.first;
                long long new_d = it.second;
                if(d + new_d < dist[v]) {
                    dist[v] = d + new_d;
                    cnt[v] = cnt[u];
                    pq.push({dist[v], v});
                }
                else if(d + new_d == dist[v]) {
                    cnt[v] += cnt[u];
                    cnt[v] %= MOD;
                }
            }
        }

        return cnt[n - 1];
    }
};
