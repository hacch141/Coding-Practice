// 2872. Maximum Number of K-Divisible Components

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(n == 1) return 1;

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 1) {
                q.push(i);
            }
        }
        
        int ans = 0;
        while(!q.empty()) {
            int u = q.front(), val = values[u];
            q.pop();
            int rem = val % k;
            if(rem == 0) {
                ans++;
            }
            for(auto v : adj[u]) {
                indegree[v]--;
                if (indegree[v] >= 0) {
                    values[v] += rem;
                }
                if(indegree[v] == 1) {
                    q.push(v);
                }
            }
        }
        
        return ans;
    }
};
