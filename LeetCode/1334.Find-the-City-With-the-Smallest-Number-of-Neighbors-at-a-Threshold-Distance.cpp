// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<pair<int,int>> adj[n];
        for(auto it : edges) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<vector<int>> dist;
        
        for(int i=0; i<n; i++) {
            vector<int> dis(n,1e9);
            dis[i] = 0;
            pq.push({0,i});
            while(!pq.empty()) {
                int d = pq.top().first;
                int u = pq.top().second;
                pq.pop();
                for(auto it : adj[u]) {
                    int v = it.first;
                    int weight = it.second;
                    if(d+weight < dis[v]) {
                        dis[v] = d + weight;
                        pq.push({dis[v],v});
                    }
                }
            }
            dist.push_back(dis);
        }
        int cityCnt = n;
        int cityNo = -1;
        for(int u=0; u<n; u++) {
            int cnt = 0;
            for(int v=0; v<n; v++) {
                if(dist[u][v] <= distanceThreshold) {
                    cnt++;
                }
            }
            if(cnt <= cityCnt) {
                cityCnt = cnt;
                cityNo = u;
            }
        }
        return cityNo;
    }
};
