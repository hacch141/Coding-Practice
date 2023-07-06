// Kahn's Algorithm

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
