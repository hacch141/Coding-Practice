// Minimum Spanning Tree

// Kruskal’s Algorithm (Disjoint Set)

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
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        DisjointSet ds(V);
        vector<pair<int,pair<int,int>>> edges;
        for(int u=0; u<V; u++) {
            for(auto it : adj[u]) {
                int v = it[0];
                int w = it[1];
                edges.push_back({w,{u,v}});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        int sum = 0;
        for(auto it : edges) {
            int u = it.second.first;
            int v = it.second.second;
            int w = it.first;
            if(ds.findPar(u) != ds.findPar(v)) {
                sum += w;
                ds.unionBySize(u,v);
            }
        }
        
        return sum;
    }
};

// T : O(V+E)edges + O(E*logE)sort + O(E*4α*2)Disjoint Set
// S : O(V)DJparent + O(V)DJsize + O(E)edges
