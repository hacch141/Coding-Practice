// 2959. Number of Possible Sets of Closing Branches

class Solution {
public:
    bool is_ok(int mask, int n, int maxDistance, vector<vector<int>>& roads) {
        vector<int> v;
        // choose only those nodes whose bits are set and go via only through them 
        for(int i = 0; i < n; i++) {
            if((mask >> i) & 1) v.push_back(i);
        }

        vector<vector<int>> adj(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++) adj[i][i] = 0;

        for(auto &it : roads) {
            adj[it[0]][it[1]] = min(adj[it[0]][it[1]],it[2]);
            adj[it[1]][it[0]] = min(adj[it[1]][it[0]],it[2]);
        }

        // Floyd Warshall to find shortest distance from any node to any other node
        for(int via = 0; via < v.size(); via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    int via_val = v[via];
                    adj[i][j] = min(adj[i][j], adj[i][via_val] + adj[via_val][j]);
                }
            }
        }

        for(int i = 0; i < v.size(); i++) {
            for(int j = i + 1; j < v.size(); j++) {
                if(adj[v[i]][v[j]] > maxDistance) return false;
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
