// 3243. Shortest Distance After Road Addition Queries I

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> dp(n, 0), ans;
        for(int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
            dp[i + 1] = 1 + dp[i];
        }
        for(auto it : queries) {
            adj[it[0]].push_back(it[1]);
            if(1 + dp[it[0]] < dp[it[1]]) {
                queue<int> q;
                q.push(it[0]);
                while(!q.empty()) {
                    int sz = q.size();
                    while(sz--) {
                        int u = q.front();
                        q.pop();
                        for(auto v : adj[u]) {
                            if(1 + dp[u] < dp[v]) {
                                q.push(v);
                                dp[v] = 1 + dp[u];
                            }
                        }
                    }
                }
            }
            ans.push_back(dp[n - 1]);
        }
        return ans;
    }
};

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
