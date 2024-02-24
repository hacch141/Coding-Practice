// 2092. Find All People With Secret

class DisjointSet {
public:
    vector<int> parent,rank;
    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    
    int par(int node) {
        return parent[node] = ((node == parent[node]) ? node : par(parent[node]));
    }
    
    void add(int u, int v) {
        int ulp_u = par(u), ulp_v = par(v);
        if(ulp_u != ulp_v) {
            if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
    }

    void remove(int u) {
        parent[u] = u;
    }
};

class Solution {
public:

    static bool cmp(vector<int>& v1, vector<int>& v2) {
        return v1[2] < v2[2];
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),cmp);
        DisjointSet ds(n);
        ds.add(0, firstPerson);

        int ptr = 0, len = meetings.size();
        while(ptr < len) {
            int t = meetings[ptr][2];
            vector<int> ppl;
            while(ptr < len && meetings[ptr][2] == t) {
                int u = meetings[ptr][0];
                int v = meetings[ptr][1];
                ppl.push_back(u);
                ppl.push_back(v);
                ds.add(u , v);
                ptr++;
            }
            for(auto u : ppl) {
                if(ds.par(u) != ds.par(0)) ds.remove(u);
            }
        }

        vector<int> ans;
        ans.push_back(0);
        for(int u = 1; u < n; u++) {
            if(ds.par(u) == ds.par(0)) ans.push_back(u);
        }

        return ans;
    }
};
