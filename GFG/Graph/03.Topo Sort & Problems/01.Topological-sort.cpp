// Topological sort

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
