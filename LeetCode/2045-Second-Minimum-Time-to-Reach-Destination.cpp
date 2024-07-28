// 2045. Second Minimum Time to Reach Destination
class Solution {
public:

    int dijkstra(vector<vector<int>>& adj, int time, int change) {
        int n = adj.size();
        vector<int> dist1(n, 1e9), dist2(n, 1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,0});
        dist1[0] = 0;
        while(!pq.empty()) {
            int du = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            int div = (du / change);
            if(div & 1) du = (div + 1) * change;

            for(auto v : adj[u]) {
                int dv = time;
                if(du + dv < dist1[v]) {
                    dist2[v] = dist1[v];
                    dist1[v] = du + dv;
                    pq.push({du + dv, v});
                }
                else if(du + dv < dist2[v] && du + dv != dist1[v]) {
                    dist2[v] = du + dv;
                    pq.push({du + dv , v});
                }
            }
        }
        return dist2[n - 1];
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n);
        for(auto i : edges) {
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        return dijkstra(adj, time, change);
    }
};
