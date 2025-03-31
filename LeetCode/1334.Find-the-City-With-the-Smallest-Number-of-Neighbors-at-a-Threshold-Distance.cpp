// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

// Floyd Warshall
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, 1e9));

        for(int i = 0; i < n; i++) adj[i][i] = 0;

        for(auto &it : edges) {
            adj[it[0]][it[1]] = it[2];
            adj[it[1]][it[0]] = it[2];
        }

        for(int via = 0; via < n; via++) {
            for(int u = 0; u < n; u++) {
                for(int v = 0; v < n; v++) {
                    adj[u][v] = min(adj[u][v], adj[u][via] + adj[via][v]);
                }
            }
        }

        int ans = -1, mn_city_cnt = 1e9;
        for(int u = 0; u < n; u++) {
            int curr_cnt = 0;
            for(int v = 0; v < n; v++) {
                if(u == v) continue;
                curr_cnt += adj[u][v] <= distanceThreshold;
            }
            if(ans == -1 || curr_cnt <= mn_city_cnt) {
                mn_city_cnt = curr_cnt;
                ans = u;
            }
        }

        return ans;
    }
};

// =================================================================

// Dijkstra
class Solution {
public:

    int dijkstra(int start, int& n, vector<vector<pair<int,int>>>& adj, int distanceThreshold) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, start});

        vector<int> dist(n, 1e9);
        dist[start] = 0;

        while(!pq.empty()) {
            int du = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for(auto it : adj[u]) {
                int v = it.first;
                int dv = it.second;
                if(du + dv < dist[v] && du + dv <= distanceThreshold) {
                    pq.push({du + dv, v});
                    dist[v] = du + dv;
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(dist[i] != 1e9) cnt++;
        }
        return cnt - 1;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i : edges) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        pair<int,int> p = {1e9, 1e9};
        for(int i = 0; i < n; i++) {
            int nodes = bfs(i, n, adj, distanceThreshold);
            if(nodes <= p.second) {
                p = {i, nodes};
            }
        }

        return p.first;
    }
};
