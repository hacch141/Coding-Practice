// 3123. Find Edges in Shortest Paths

// Dijkstra
class Solution {
public:
    vector<int> dijkstra(int st, int n, vector<vector<pair<int,int>>>& adj) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, st});

        vector<int> dist(n, 1e9);
        dist[st] = 0;

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int d = curr.first;
            int u = curr.second;
            for(auto &it : adj[u]) {
                int v = it.first;
                int new_d = it.second;
                if(d + new_d < dist[v]) {
                    dist[v] = d + new_d;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> zero_to_n = dijkstra(0, n, adj);
        vector<int> n_to_zero = dijkstra(n - 1, n, adj);

        int len = edges.size();
        vector<bool> ans(len, false);

        for(int i = 0; i < len; i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if((zero_to_n[u] + w + n_to_zero[v] == zero_to_n[n - 1]) || (n_to_zero[u] + w + zero_to_n[v] == zero_to_n[n - 1])) {
                ans[i] = true;
            }
        }

        return ans;
    }
};

// ================================================================================================

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});

        vector<int> dist(n, 1e9);
        dist[0] = 0;

        vector<vector<int>> prev(n);

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int d = curr.first;
            int u = curr.second;
            for(auto it : adj[u]) {
                int v = it.first;
                int new_d = it.second;
                if(d + new_d < dist[v]) {
                    dist[v] = d + new_d;
                    pq.push({dist[v], v});
                    prev[v] = {};
                    prev[v].push_back(u);
                }
                else if(d + new_d == dist[v]) {
                    prev[v].push_back(u);
                }
            }
        }

        set<pair<int,int>> st;
        vector<bool> vis(n, false);

        queue<int> q;
        q.push(n - 1);

        while(!q.empty()) {
            int v = q.front();
            q.pop();

            if(vis[v]) continue;
            vis[v] = true;

            for(auto &u : prev[v]) {
                q.push(u);
                st.insert({u, v});
                st.insert({v, u});
            }
        }

        vector<bool> ans;
        for(auto &it : edges) {
            ans.push_back(st.count({it[0], it[1]}));
        }

        return ans;
    }
};
