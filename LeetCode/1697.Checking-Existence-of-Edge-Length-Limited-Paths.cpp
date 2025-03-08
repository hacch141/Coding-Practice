// 1697. Checking Existence of Edge Length Limited Paths

class DisjointSet {
private:
    vector<int> parent, sz;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find_par(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find_par(parent[u]);
    }

    void union_by_size(int u, int v) {
        int par_u = find_par(u), par_v = find_par(v);
        if(par_u == par_v) {
            return;
        }
        else if(sz[par_u] > sz[par_v]) {
            sz[par_u] += sz[par_v];
            parent[par_v] = par_u;
        }
        else {
            sz[par_v] += sz[par_u];
            parent[par_u] = par_v;
        }
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int len = queries.size();
        for(int i = 0; i < len; i++) {
            queries[i].push_back(i);
        }

        auto lambda = [&](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];
        };

        sort(queries.begin(), queries.end(), lambda);
        sort(edgeList.begin(), edgeList.end(), lambda);

        vector<bool> ans(len);
        DisjointSet ds(n);
        int ind = 0;
        for(int i = 0; i < len; i++) {
            while(ind < edgeList.size() && edgeList[ind][2] < queries[i][2]) {
                ds.union_by_size(edgeList[ind][0], edgeList[ind][1]);
                ind++;
            }
            int u = queries[i][0], v = queries[i][1];
            ans[queries[i][3]] = (ds.find_par(u) == ds.find_par(v));
        }

        return ans;
    }
};
