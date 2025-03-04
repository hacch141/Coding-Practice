// 1466. Reorder Routes to Make All Paths Lead to the City Zero

// dfs
class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<set<int>>& can_go, vector<bool>& vis, int& cnt) {
        vis[u] = true;
        for(auto &v : adj[u]) {
            if(!vis[v]) {
                if(can_go[u].count(v)) cnt++;
                dfs(v, adj, can_go, vis, cnt);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<set<int>> can_go(n);
        for(auto &it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            can_go[it[0]].insert(it[1]);
        }

        int cnt = 0;
        vector<bool> vis(n, false);

        dfs(0, adj, can_go, vis, cnt);

        return cnt;
    }
};

// bfs
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<set<int>> can_go(n);
        for(auto &it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            can_go[it[0]].insert(it[1]);
        }

        queue<int> q;
        q.push(0);
        int cnt = 0;
        vector<bool> vis(n, false);

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int u = q.front();
                q.pop();
                vis[u] = true;
                for(auto &v : adj[u]) {
                    if(!vis[v]) {
                        if(can_go[u].count(v)) cnt++;
                        q.push(v);
                    }
                }
            }
        }

        return cnt;
    }
};

//================================================================================

class Solution {
public:
    void bfs(int& cnt, vector<vector<int>>& adj, int& n) {
        queue<int> q;
        q.push(0);
        vector<int> vis(n,0);
        vis[0] = 1;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto i : adj[curr]) {
                int next = abs(i);
                if(!vis[next]) {
                    vis[next] = 1;
                    q.push(next);
                    if(i>0) cnt++;
                }
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(auto& i : connections) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(-i[0]);
        }

        int cnt = 0;
        bfs(cnt,adj,n);
        return cnt;
    }
};
