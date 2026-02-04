// Account Merge

class DisjointSet {
    int[] parent, size;
    public DisjointSet(int n) {
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    public int findParent(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }

    public void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            size[pv] += size[pu];
            parent[pu] = parent[pv];
        }
        else {
            size[pu] += size[pv];
            parent[pv] = parent[pu];
        }
    }
}

class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        int n = accounts.size();
        DisjointSet ds = new DisjointSet(n);

        Map<String,Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts.get(i).size(); j++) {
                String mail = accounts.get(i).get(j);
                if (!mp.containsKey(mail)) {
                    mp.put(mail, i);
                }
                else {
                    ds.unionBySize(mp.get(mail), i);
                }
            }
        }

        List<String>[] merged = new ArrayList[n];
        for (int i = 0; i < n; i++) merged[i] = new ArrayList<>();

        for (Map.Entry<String,Integer> s : mp.entrySet()) {
            String mail = s.getKey();
            int ind = s.getValue();
            int root = ds.findParent(ind);
            merged[root].add(mail);
        }

        List<List<String>> ans = new ArrayList<>();
        for (List<String> m : merged) {
            if (m.size() == 0) continue;

            Collections.sort(m);
            List<String> curr = new ArrayList<>();

            int ind = mp.get(m.get(0));
            String name = accounts.get(ind).get(0);

            curr.add(name);
            curr.addAll(m);
            ans.add(curr);
        }

        return ans;
    }
}

// ====================================================================

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
