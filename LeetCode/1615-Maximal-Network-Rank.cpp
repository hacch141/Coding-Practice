// 1615. Maximal Network Rank

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<set<int>> adj(n);
        for(auto &it : roads) {
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }

        int ans = 0;
        for(int u = 0; u < n; u++) {
            for(int v = u + 1; v < n; v++) {
                if(adj[u].count(v)) ans = max(ans, (int)adj[u].size() + (int)adj[v].size() - 1);
                else ans = max(ans, (int)adj[u].size() + (int)adj[v].size());
            }
        }

        return ans;
    }
};

// ======================================

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n, vector<int>(n,-1));
        vector<int> freq(n,0);
        for(auto i : roads) {
            adj[i[0]][i[1]] = 1;
            adj[i[1]][i[0]] = 1;
            freq[i[0]]++;
            freq[i[1]]++;
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n && i!=j; j++) {
                int rank = freq[i] + freq[j];
                if(adj[i][j] == 1) {
                    rank--;
                }
                ans = max(ans,rank);
            }
        }

        return ans;
    }
};

