// 3243. Shortest Distance After Road Addition Queries I

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dp(n, 0);
        vector<vector<int>> adj(n);
        for(int i = n - 2; i >= 0; i--) {
            adj[i + 1].push_back(i);
            dp[i] = dp[i + 1] + 1;
        }

        vector<int> ans;
        for(auto it : queries) {
            int u = it[0], v = it[1];
            if(1 + dp[v] < dp[u]) {
                dp[u] = 1 + dp[v];
                queue<int> q;
                q.push(u);
                while(!q.empty()) {
                    int cur = q.front();
                    int d = dp[cur];
                    q.pop();
                    for(auto neg : adj[cur]) {
                        if(1 + d < dp[neg]) {
                            dp[neg] = 1 + dp[cur];
                            q.push(neg);
                        }
                    }
                }
            }
            ans.push_back(dp[0]);
            adj[v].push_back(u);
        }
        return ans;
    }
};
