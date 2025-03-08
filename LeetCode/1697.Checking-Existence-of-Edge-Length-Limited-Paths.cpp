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
    static bool cmp(pair<int, vector<int>>& p1, pair<int, vector<int>>& p2) {
        return p1.second[2] < p2.second[2];
    }

    static bool cmp2(vector<int>& v1, vector<int>& v2) {
        return v1[2] < v2[2];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int len = queries.size();

        vector<pair<int, vector<int>>> new_queries;
        for(int i = 0; i < len; i++) {
            new_queries.push_back({i, queries[i]});
        }

        sort(new_queries.begin(), new_queries.end(), cmp);
        sort(edgeList.begin(), edgeList.end(), cmp2);

        vector<bool> ans(len);
        DisjointSet ds(n);
        int ind = 0;
        for(int i = 0; i < len; i++) {
            while(ind < edgeList.size() && edgeList[ind][2] < new_queries[i].second[2]) {
                ds.union_by_size(edgeList[ind][0], edgeList[ind][1]);
                ind++;
            }
            int u = new_queries[i].second[0], v = new_queries[i].second[1];
            ans[new_queries[i].first] = (ds.find_par(u) == ds.find_par(v));
        }

        return ans;
    }
};
