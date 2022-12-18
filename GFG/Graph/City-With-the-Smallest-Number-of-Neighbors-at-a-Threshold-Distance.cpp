class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n,INT_MAX));
        for(auto it : edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for(int i=0; i<n; i++) dist[i][i] = 0;
        
        for(int v=0; v<n; v++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(dist[i][v]==INT_MAX || dist[v][j]==INT_MAX) continue;
                    dist[i][j] = min(dist[i][j] , dist[i][v]+dist[v][j]);
                }
            }
        }
        
        int cityCnt = n;
        int cityNo = -1;
        
        for(int city=0; city<n; city++) {
            int cnt = 0;
            for(int i=0; i<n; i++) {
                if(dist[city][i] <= distanceThreshold) {
                    cnt++;
                }
            }
            if(cnt <= cityCnt) {
                cityCnt = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }
};


// dijkstra algorithm Priority Queue
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
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
