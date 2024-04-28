// 834. Sum of Distances in Tree

class Solution {
public:

    int sum;

    void dfs(int u, int p, vector<vector<int>>& tree, vector<int>& cnt, vector<int>& ans) {
        for(auto v : tree[u]) {
            if(v == p) continue;
            dfs(v, u, tree, cnt, ans);
            cnt[u] += cnt[v];
            ans[u] += ans[v] + cnt[v];
        }
    }

    void dfs1(int u, int p, vector<vector<int>>& tree, vector<int>& cnt, vector<int>& ans, int& n) {
        for(auto v : tree[u]) {
            if(v == p) continue;
            ans[v] = ans[u] - cnt[v] + (n - cnt[v]);
            dfs1(v, u, tree, cnt, ans, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tree(n);
        for(auto i : edges) {
            tree[i[0]].push_back(i[1]);
            tree[i[1]].push_back(i[0]);
        }

        vector<int> cnt(n, 1), ans(n, 0);
        dfs(0, 0, tree, cnt, ans);
        dfs1(0, 0, tree, cnt, ans, n);
        return ans;
    }
};
