// 2285. Maximum Total Importance of Roads

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n, 0);
        for(auto i : roads) {
            int u = i[0], v = i[1];
            indegree[u]++;
            indegree[v]++;
        }
        sort(indegree.rbegin(), indegree.rend());
        long long imp = 0;
        for(int i = 0; i < n; i++) {
            imp += 1LL * indegree[i] * (n - i);
        }
        return imp;
    }
};
