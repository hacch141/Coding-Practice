// 2101. Detonate the Maximum Bombs

class Solution {
public:

    void bfs(int start, vector<int>& vis, vector<vector<int>>& adj, int& cnt) {
        vis[start] = 1;
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;
            for(auto v : adj[u]) {
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        long long x1,x2,y1,y2,r1,r2,d;
        for(int i=0; i<n; i++) {
            x1 = bombs[i][0];
            y1 = bombs[i][1];
            r1 = bombs[i][2];
            for(int j=0; j<n && i!=j; j++) {
                x2 = bombs[j][0];
                y2 = bombs[j][1];
                r2 = bombs[j][2];
                d = ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2));
                if(r1*r1>=d) adj[i].push_back(j);
                if(r2*r2>=d) adj[j].push_back(i);
            }
        }

        vector<int> vis(n,0);
        int ans = 0;
        int cnt = 0;
        for(int i=0; i<n; i++) {
            cnt = 0;
            bfs(i,vis,adj,cnt);
            ans = max(ans,cnt);
            fill(vis.begin(),vis.end(),0);
        }

        return ans;
    }
};
