// 1584. Min Cost to Connect All Points

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        // Prims Algo
        vector<bool> vis(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        
        int sum = 0;
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int d = curr.first, u = curr.second;
            if(vis[u]) continue;
            vis[u] = true;
            sum += d;
            for(auto &it : adj[u]) {
                int v = it.first, newd = it.second;
                if(!vis[v]) pq.push({newd, v});
            }
        }

        return sum;
    }
};

