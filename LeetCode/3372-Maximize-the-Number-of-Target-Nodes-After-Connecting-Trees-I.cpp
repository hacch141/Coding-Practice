// 3372. Maximize the Number of Target Nodes After Connecting Trees I

class Solution {
public:
    int get_cnt_nodes(int st, vector<vector<int>>& adj, int k) {
        int n = adj.size();

        queue<int> q;
        q.push(st);

        vector<int> vis(n, false);
        vis[st] = true;

        int lvl = 0, cnt = 0;
        while(!q.empty()) {
            if(lvl == k) break;
            int sz = q.size();
            while(sz--) {
                int u = q.front();
                q.pop();
                cnt++;
                for(auto &v : adj[u]) {
                    if(!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
            lvl++;
        }

        return cnt;
    }

    int get_mx_tree(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int mx = 0;
        for(int i = 0; i < n; i++) {
            mx = max(mx, get_cnt_nodes(i, adj, k));
        }

        return mx;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int mx_cnt_2 = get_mx_tree(edges2, k);

        int n = edges1.size() + 1;
        vector<vector<int>> adj(n);
        for(auto &it : edges1) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(get_cnt_nodes(i, adj, k + 1) + mx_cnt_2);
        }

        return ans;
    }
};
