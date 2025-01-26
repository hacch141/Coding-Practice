// 1584. Min Cost to Connect All Points

// Prims Algo
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



// Krushkal's Algo
class DisjointSet {
private:
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int find_par(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find_par(parent[u]);
    }

    void union_by_rank(int u, int v) {
        int par_u = find_par(u);
        int par_v = find_par(v);
        if(par_u == par_v) {
            return;
        }
        else if(rank[par_u] > rank[par_v]) {
            parent[par_v] = par_u;
        }
        else if(rank[par_u] < rank[par_v]) {
            parent[par_u] = par_v;
        }
        else {
            parent[par_v] = par_u;
            rank[par_u]++;
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<int>> edg;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edg.push_back({i, j, d});
                edg.push_back({j, i, d});
            }
        }

        auto cmp = [&](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];
        };

        sort(edg.begin(), edg.end(), cmp);

        int sum = 0;
        DisjointSet ds(n);
        for(auto &e : edg) {
            int u = e[0], v = e[1], w = e[2];
            int p1 = ds.find_par(u);
            int p2 = ds.find_par(v);
            if(p1 != p2) {
                sum += w;
                ds.union_by_rank(u, v);
            }
        }

        return sum;
    }
};


