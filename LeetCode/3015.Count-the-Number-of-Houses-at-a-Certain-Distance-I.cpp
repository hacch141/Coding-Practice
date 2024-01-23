// 3015. Count the Number of Houses at a Certain Distance I

class Solution {
public:
    
    void bfs(int start, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& ans) {
        queue<int> q;
        q.push(start);
        vis[start] = true;
        int len = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                int u = q.front();
                q.pop();
                for(auto v : adj[u]) {
                    if(!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            ans[len] += q.size();
            len++;
        }
    }
    
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adj(n);
        for(int i=0; i<n-1; i++) {
            adj[i].push_back(i+1);
            adj[i+1].push_back(i);
        }
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        vector<int> ans(n,0);
        for(int i=0; i<n; i++) {
            vector<bool> vis(n,false);
            bfs(i,adj,vis,ans);
        }
        return ans;
    }
};
