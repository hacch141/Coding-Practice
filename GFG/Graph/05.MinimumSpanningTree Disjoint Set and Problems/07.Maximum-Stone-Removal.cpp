// Maximum Stone Removal

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

    public void union(int u, int v) {
        int ultParU = findParent(u);
        int ultParV = findParent(v);
        if (ultParU == ultParV) {
            return;
        }
        else if (size[ultParU] >= size[ultParV]) {
            parent[ultParV] = ultParU;
            size[ultParU] +=ultParV;
        }
        else {
            parent[ultParU] = ultParV;
            size[ultParV] +=ultParU;
        }
    }
}

class Solution {
    public int removeStones(int[][] stones) {
        int mxX = Integer.MIN_VALUE;
        int mxY = Integer.MIN_VALUE;
        for (int[] s : stones) {
            mxX = Math.max(mxX, s[0]);
            mxY = Math.max(mxY, s[1]);
        }

        Set<Integer> vis = new HashSet<>();
        DisjointSet ds = new DisjointSet(mxX + mxY + 2);
        for (int[] s : stones) {
            int x = s[0], y = s[1];
            int u = x;
            int v = mxX + y + 1;
            ds.union(u, v);
            vis.add(u);
            vis.add(v);
        }

        int components = 0;
        for (int u : vis) {
            if (u == ds.findParent(u)) {
                components++;
            }
        }

        return stones.length - components;
    }
}

// ==================================================================

class DisjointSet {
    vector<int> parent,size;
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

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones) {
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int> nodeStones;
        for(auto it : stones) {
            int u = it[0];
            int v = it[1] + maxRow + 1;
            ds.unionBySize(u,v);
            nodeStones[u] = 1;
            nodeStones[v] = 1;
        }
        
        int comp = 0;
        for(auto it : nodeStones) {
            int node = it.first;
            if(node == ds.findPar(node)) {
                comp++;
            }
        }
        
        return n - comp;
    }
};

// T : O(N * 4α)
// S : O(2* (max row index + max column index))
