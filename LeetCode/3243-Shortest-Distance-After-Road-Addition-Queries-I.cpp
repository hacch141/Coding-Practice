// 3243. Shortest Distance After Road Addition Queries I

// simple bfs
class Solution {
public:
    int bfs(int start, int end, vector<vector<int>>& adj) {
        queue<int> q;
        q.push(start);
        set<int> vis;
        vis.insert(start);
        int cnt = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int u = q.front();
                q.pop();
                if(u == end) return cnt;
                for(auto v : adj[u]) {
                    if(!vis.count(v)) {
                        q.push(v);
                        vis.insert(v);
                    }
                }
            }
            cnt++;
        }
        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> ans;
        for(int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }
        for(auto q : queries) {
            adj[q[0]].push_back(q[1]);
            ans.push_back(bfs(0, n - 1, adj));
        }
        return ans;
    }
};

// dp
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> dist(n, 0);
        for(int i = n - 2; i >= 0; i--) {
            adj[i].push_back(i + 1);
            dist[i] = 1 + dist[i + 1];
        }

        vector<int> ans;
        for(auto &it : queries) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            if(1 + dist[v] < dist[u]) {
                dist[u] = 1 + dist[v];
                for(int uu = u - 1; uu >= 0; uu--) {
                    for(auto &vv : adj[uu]) {
                        if(1 + dist[vv] < dist[uu]) {
                            dist[uu] = 1 + dist[vv];
                        }
                    }
                }
            }
            ans.push_back(dist[0]);
        }
        
        return ans;
    }
};
