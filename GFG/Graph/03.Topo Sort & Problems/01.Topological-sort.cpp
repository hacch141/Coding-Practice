// Topological sort

class Solution {
    private void dfs(int u, List<List<Integer>> adj, boolean[] vis, List<Integer> topo) {
        vis[u] = true;
        for (int v : adj.get(u)) {
            if (!vis[v]) {
                dfs(v, adj, vis, topo);
            }
        }
        topo.add(u); // post-order
    }

    // Function to return vertices in Topological order
    public int[] topoSort(int V, List<List<Integer>> adj) {

        boolean[] vis = new boolean[V];
        List<Integer> topo = new ArrayList<>();

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, topo);
            }
        }

        // reverse post-order
        Collections.reverse(topo);

        // convert to int[]
        int[] res = new int[V];
        for (int i = 0; i < V; i++) {
            res[i] = topo.get(i);
        }

        return res;
    }
}

class Solution {
    // Function to return list containing vertices in Topological order
    public int[] topoSort(int V, List<List<Integer>> adj) {

        int[] indegree = new int[V];

        // Calculate indegree
        for (int u = 0; u < V; u++) {
            for (int v : adj.get(u)) {
                indegree[v]++;
            }
        }

        Queue<Integer> q = new LinkedList<>();

        // Push nodes with indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }

        int[] topo = new int[V];
        int idx = 0;

        // BFS
        while (!q.isEmpty()) {
            int u = q.poll();
            topo[idx++] = u;

            for (int v : adj.get(u)) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.offer(v);
                }
            }
        }

        return topo;
    }
}

// ============================================================================

// BFS
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> topo;
	    vector<int> indegree(V,0);
	    
	    for(int u=0; u<V; u++) {
	        for(auto v : adj[u]) {
	            indegree[v]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0; i<V; i++) {
	        if(indegree[i] == 0) {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()) {
	        int u = q.front();
	        topo.push_back(u);
	        q.pop();
	        for(auto v : adj[u]) {
	            indegree[v]--;
	            if(indegree[v] == 0) q.push(v);
	        }
	    }
	    
	    return topo;
	}
};

// T : O(V + 2*E)
// S : O(V)


// DFS
class Solution
{
    
    private:
    void dfs(int u, vector<int> adj[], vector<int>& vis, vector<int>& topo) {
        vis[u] = 1;
        for(auto v : adj[u]) {
            if(!vis[v]) {
                dfs(v,adj,vis,topo);
            }
        }
        topo.push_back(u);
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> topo;
	    vector<int> vis(V,0);
	    
	    for(int i=0; i<V; i++) {
	        if(!vis[i]) {
	            dfs(i,adj,vis,topo);
	        }
	    }
	    reverse(topo.begin(),topo.end());
	    return topo;
	}
};

// T : O(V + 2*E)
// S : O(V)
