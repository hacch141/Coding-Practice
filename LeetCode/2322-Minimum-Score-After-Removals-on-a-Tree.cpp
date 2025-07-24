// 2322. Minimum Score After Removals on a Tree

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        unordered_map<int, vector<int>> adj;
        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> xorFromRoot(n, 0);
        vector<int> parent(n, -1);
        vector<int> inTime(n, 0);
        vector<int> outTime(n, 0);
        int timer = 0;

        function<void(int, int)> dfs = [&](int node, int par) {
            xorFromRoot[node] = nums[node];
            parent[node] = par;
            inTime[node] = timer++;

            for (int ngbr : adj[node]) {
                if (ngbr != par) {
                    dfs(ngbr, node);
                    xorFromRoot[node] ^= xorFromRoot[ngbr];
                }
            }

            outTime[node] = timer++;
        };

        dfs(0, -1);

        // Check if v is descendant of u
        function<bool(int, int)> isDescendant = [&](int u, int v) {
            return inTime[v] > inTime[u] && outTime[v] < outTime[u];
        };

        // Score computation
        function<int(int, int, int)> getScore = [](int a, int b, int c) {
            int maxXor = max({a, b, c});
            int minXor = min({a, b, c});
            return maxXor - minXor;
        };

        int result = INT_MAX;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x, y, z;
                if (isDescendant(i, j)) {
                    x = xorFromRoot[j];
                    y = xorFromRoot[i] ^ xorFromRoot[j];
                    z = xorFromRoot[0] ^ xorFromRoot[i];
                } else if (isDescendant(j, i)) {
                    x = xorFromRoot[i];
                    y = xorFromRoot[j] ^ xorFromRoot[i];
                    z = xorFromRoot[0] ^ xorFromRoot[j];
                } else {
                    x = xorFromRoot[i];
                    y = xorFromRoot[j];
                    z = xorFromRoot[0] ^ x ^ y;
                }

                result = min(result, getScore(x, y, z));
            }
        }

        return result;
    }
};

