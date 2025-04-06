// 3419. Minimize the Maximum Edge Weight of Graph

class Solution {
public:

    bool ok(int mx_w, int st, int& n, vector<vector<pair<int,int>>>& adj) {
        vector<bool> vis(n, false);
        vis[0] = true;

        queue<int> q;
        q.push(0);

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto &it : adj[u]) {
                int v = it.first;
                int w = it.second;
                if(!vis[v] && w <= mx_w) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(!vis[i]) return false;
        }
        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<int> w;
        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : edges) {
            adj[it[1]].push_back({it[0], it[2]});
            w.push_back(it[2]);
        }

        sort(w.begin(), w.end());

        int low = 0, high = w.size() - 1, ans = -1;
        while(low <= high) {
            int mid = (high - low) / 2 + low;
            if(ok(w[mid], 0, n, adj)) {
                ans = w[mid];
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
