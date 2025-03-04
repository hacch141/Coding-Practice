// 2360. Longest Cycle in a Graph

// dfs
class Solution {
public:
    void dfs(int u, vector<int>& edges, vector<bool>& vis, vector<bool>& path_vis, vector<int>& cnt, int& ans) {
        vis[u] = true;
        path_vis[u] = true;
        int v = edges[u];
        if(v != -1) {
            if(!vis[v]) {
                cnt[v] += cnt[u];
                dfs(v, edges, vis, path_vis, cnt, ans);
            }
            else if(path_vis[v]) {
                ans = max(ans, cnt[u] - cnt[v] + 1);
            }
        }
        path_vis[u] = false;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size(), ans = -1;
        vector<int> cnt(n, 1);
        vector<bool> vis(n, false), path_vis(n, false);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i, edges, vis, path_vis, cnt, ans);
        }

        return ans;
    }
};

// ====================================================================

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), ans = -1;
        vector<int> cnt(n, 1);
        vector<bool> curr_vis(n, false);

        for(int i = 0; i < edges.size(); i++) {
            fill(curr_vis.begin(), curr_vis.end(), false);
            int u = i;
            curr_vis[u] = true;
            if(edges[u] == -1) continue;
            while(edges[u] != -1) {
                int v = edges[u];
                if(curr_vis[v]) ans = max(ans, cnt[u] - cnt[v] + 1);
                edges[u] = -1;
                curr_vis[v] = true;
                cnt[v] += cnt[u];
                u = v;
            }
        }

        return ans;
    }
};
