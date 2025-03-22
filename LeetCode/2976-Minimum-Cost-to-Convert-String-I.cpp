// 2976. Minimum Cost to Convert String I

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int len = original.size();

        vector<vector<int>> adj(26, vector<int>(26, 1e9));
        for(int i = 0; i < 26; i++) adj[i][i] = 0;

        for(int x = 0; x < len; x++) {
            int i = original[x] - 'a';
            int j = changed[x] - 'a';
            adj[i][j] = min(adj[i][j], cost[x]);
        }

        // Floyd Warshall
        for(int via = 0; via < 26; via++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }

        long long total_cost = 0;
        for(int x = 0; x< source.length(); x++) {
            int i = source[x] - 'a';
            int j = target[x] - 'a';
            if(adj[i][j] == 1e9) return -1;
            total_cost += adj[i][j];
        }

        return total_cost;
    }
};

// ==================================================================================

class Solution {
public:

    vector<long long> dijkstra(int start, vector<vector<pair<int,int>>>& adj) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, start});

        vector<long long> dist(26, 1e15);
        dist[start] = 0;

        while(!pq.empty()) {
            int du = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for(auto it : adj[u]) {
                int v = it.first;
                int dv = it.second;
                if(du + dv < dist[v]) {
                    pq.push({du + dv, v});
                    dist[v] = du + dv;
                }
            }
        }

        return dist;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>> adj(26);
        int n = original.size();
        for(int i = 0; i < n; i++) {
            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }

        vector<vector<long long>> uTOv(26);
        for(int i = 0; i < 26; i++) {
            uTOv[i] = dijkstra(i, adj);
        }

        long long cst = 0, len = source.length();
        for(int i = 0; i < len; i++) {
            int u = source[i] - 'a', v = target[i] - 'a';
            if(uTOv[u][v] == 1e15) return -1;
            cst += uTOv[u][v];
        }

        return cst;
    }
};
