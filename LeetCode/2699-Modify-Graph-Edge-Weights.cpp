// 2699. Modify Graph Edge Weights

class Solution {
public:
    const int INF = 2e9;
    typedef pair<int,int> pi; 

    int dijkstra(int n, int source, int destination, vector<pi> adj[]) {
        vector<int> dist(n, INT_MAX);
        dist[source] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, source}); 

        while (!pq.empty()) {
            auto [cost, node] = pq.top(); pq.pop();
            if (node == destination) break;
            for (auto [ccost, cnode] : adj[node]) {
                if (cost + ccost < dist[cnode]) {
                    dist[cnode] = cost + ccost;
                    pq.push({dist[cnode], cnode});
                }
            }
        }
        return dist[destination];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<pi> adj[n]; 
        for (auto &e : edges) {
            if (e[2] == -1) continue; 
            adj[e[0]].push_back({e[2], e[1]});
            adj[e[1]].push_back({e[2], e[0]});
        }
        int d = dijkstra(n, source, destination, adj);
        if (d < target) return {};

        bool isEqual = d == target; 
        for (auto &e : edges) {
            if (e[2] != -1) continue;
            e[2] = isEqual ? INF : 1;
            adj[e[0]].push_back({e[2], e[1]}); 
            adj[e[1]].push_back({e[2], e[0]}); 
            if (!isEqual) {
                int newd = dijkstra(n, source, destination, adj);
                if (newd <= target) {
                    isEqual = true; 
                    e[2] += target - newd; 
                }
            }
        }  

        if (isEqual) return edges;
        return {}; 
    }
};
