// Account Merge

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }
    
    int findPar(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u == ulp_v) {
            return;
        }
        if(size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n = accounts.size();
        DisjointSet ds(n);
        
        unordered_map<string,int> mp;
        for(int i=0; i<n; i++) {
            for(int j=1; j<accounts[i].size(); j++) {
                string s = accounts[i][j];
                if(mp.find(s) == mp.end()) {
                    mp[s] = i;
                }
                else {
                    ds.unionBySize(i,mp[s]);
                }
            }
        }
        
        vector<vector<string>> mergedMails(n);
        for(auto it : mp) {
            string mail = it.first;
            int node = ds.findPar(it.second);
            mergedMails[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i=0; i<n; i++) {
            if(mergedMails[i].size() == 0) {
                continue;
            }
            else {
                vector<string> v;
                v.push_back(accounts[i][0]);
                sort(mergedMails[i].begin(), mergedMails[i].end());
                for(auto it : mergedMails[i]) {
                    v.push_back(it);
                }
                ans.push_back(v);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// T : O(N+E) + O(E*4ɑ) + O(N*(ElogE + E))
// S : O(N*E)
