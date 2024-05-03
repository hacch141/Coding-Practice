// 721. Accounts Merge

// ======================================== DISJOINT SET ==============================================
class DisjointSet {
public:
    vector<int> parent,rank;
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1,0);
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
// ====================================================================================================

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        
        map<string,int> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string s = accounts[i][j];
                if(mp.find(s) == mp.end()) {
                    mp[s] = i;
                }
                else {
                    ds.add(i,mp[s]);
                }
            }
        }

        map<int,set<string>> mp2;
        for(int i = 0; i < n; i++) {
            int par = ds.par(i);
            for(int j = 1; j < accounts[i].size(); j++) {
                string s = accounts[i][j];
                mp2[par].insert(s);
            }
        }

        vector<vector<string>> ans;
        for(auto i : mp2) {
            string name = accounts[i.first][0];
            vector<string> v;
            v.push_back(name);
            v.insert(v.end(), i.second.begin(), i.second.end());
            ans.push_back(v);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
