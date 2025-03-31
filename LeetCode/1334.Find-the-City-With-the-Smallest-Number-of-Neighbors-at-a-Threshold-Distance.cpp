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

// dijkstra Code With Mik
class Solution {
public:
    #define P pair<int, int>

    // Khandaani Dijkstra's algorithm to find shortest paths from a source city
    void dijkstra(int n, unordered_map<int, vector<P>>& adj, vector<int>& result, int S) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, S});
        fill(result.begin(), result.end(), INT_MAX);
        result[S] = 0;  // Distance to source itself is zero

        // Process nodes in priority order
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& p : adj[node]) {
                int adjNode = p.first;
                int dist = p.second;

                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }
    }

    int getCityWithFewestReachable(int n, const vector<vector<int>>& shortestPathMatrix, int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = INT_MAX;

        // Count number of cities reachable within the distance threshold for each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }

            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<P>> adj;

        vector<vector<int>> shortestPathMatrix(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            shortestPathMatrix[i][i] = 0;  // Distance to itself is zero
        }

        for (const auto& edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            adj[start].push_back({end, weight});
            adj[end].push_back({start, weight});
        }

        // Compute shortest paths from each city using Dijkstra's algorithm
        for (int i = 0; i < n; i++) {
            dijkstra(n, adj, shortestPathMatrix[i], i);
        }

        return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
    }
};

// =============================================================================

// bellman ford Code With Mik
class Solution {
public:
    #define P pair<int, int>

    void bellmanFord(int n, vector<vector<int>>& edges, vector<int>& shortestPathDistances, int source) {
        fill(shortestPathDistances.begin(), shortestPathDistances.end(), INT_MAX);
        shortestPathDistances[source] = 0;

        for (int i = 1; i < n; i++) {
            for (const auto& edge : edges) {
                int u  = edge[0];
                int v  = edge[1];
                int wt = edge[2];
                if (shortestPathDistances[u] != INT_MAX &&
                    shortestPathDistances[u] + wt < shortestPathDistances[v]) {
                    shortestPathDistances[v] = shortestPathDistances[u] + wt;
                }
                //bi-directional edge
                if (shortestPathDistances[v] != INT_MAX &&
                    shortestPathDistances[v] + wt < shortestPathDistances[u]) {
                    shortestPathDistances[u] = shortestPathDistances[v] + wt;
                }
            }
        }
    }

    int getCityWithFewestReachable(int n, const vector<vector<int>>& shortestPathMatrix, int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = INT_MAX;

        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }

            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> shortestPathMatrix(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            shortestPathMatrix[i][i] = 0;  // Distance to itself is zero
        }

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            shortestPathMatrix[u][v] = wt;
            shortestPathMatrix[v][u] = wt;
        }

        // Compute shortest paths from each city using Dijkstra's algorithm
        for (int i = 0; i < n; i++) {
            bellmanFord(n, edges, shortestPathMatrix[i], i);
        }

        return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
    }
};
