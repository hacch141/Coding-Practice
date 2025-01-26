// 2127. Maximum Employees to Be Invited to a Meeting

class Solution {
public:

    int dfs(int u, vector<bool>& vis, vector<bool>& pathvis, vector<int>& cnt, vector<int>& favorite) {
        vis[u] = true;
        pathvis[u] = true;
        int v = favorite[u];
        if(pathvis[v]) {
            pathvis[u] = false;
            return cnt[u] - cnt[v] + 1;
        }
        if(vis[v]) {
            pathvis[u] = false;
            return 0;
        }
        cnt[v] += cnt[u] + 1;
        int curr = dfs(v, vis, pathvis, cnt, favorite);
        pathvis[u] = false;
        return curr;
    }

    int bfs(int st, vector<vector<int>>& rev_fav, vector<bool>& vis) {
        queue<int> q;
        q.push(st);
        int lvl = 0;
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                int u = q.front();
                q.pop();
                for(auto &v : rev_fav[u]) {
                    if(vis[v]) continue;
                    vis[v] = true;
                    q.push(v);
                }
            }
            lvl++;
        }
        return lvl;
    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<bool> vis(n, false), pathvis(n, false);
        vector<int> cnt(n, 0);

        int ans = 0;
        for(int u = 0; u < n; u++) {
            if(!vis[u]) {
                ans = max(ans, dfs(u, vis, pathvis, cnt, favorite));
            }
        }

        vector<vector<int>> rev_fav(n);
        for(int u = 0; u < n; u++) {
            int v = favorite[u];
            rev_fav[v].push_back(u);
        }

        int tmp = 0;
        for(int u = 0; u < n; u++) vis[u] = false;
        for(int u = 0; u < n; u++) {
            int v = favorite[u];
            if(favorite[v] == u && !vis[u] && !vis[v]) {
                vis[u] = true;
                vis[v] = true;
                tmp += bfs(u, rev_fav, vis);
                tmp += bfs(v, rev_fav, vis);
            }
        }
        ans = max(ans, tmp);

        return ans;
    }
};
