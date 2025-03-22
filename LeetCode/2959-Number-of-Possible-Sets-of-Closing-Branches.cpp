// 2959. Number of Possible Sets of Closing Branches

class Solution {
public:
    bool is_ok(int mask, int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++) adj[i][i] = 0;

        for(auto &it : roads) {
            if(!((mask >> it[0]) & 1) || !((mask >> it[1]) & 1)) continue;
            adj[it[0]][it[1]] = min(adj[it[0]][it[1]],it[2]);
            adj[it[1]][it[0]] = min(adj[it[1]][it[0]],it[2]);
        }

        // Floyd Warshall to find shortest distance from any node to any other node
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(!((mask >> i) & 1) || !((mask >> j) & 1)) continue;
                if(adj[i][j] > maxDistance) return false;
            }
        }

        return true;
    }

    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans = 0;
        // check all the possibility to remove the nodes
        for(int mask = 0; mask < 1 << n; mask++) {
            ans += is_ok(mask, n, maxDistance, roads);
        }

        return ans;
    }
};
