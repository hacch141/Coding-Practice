// Kahn's Algorithm

import java.util.*;

class Solution {

    // Function to return vertices in Topological order
    public int[] topoSort(int V, List<List<Integer>> adj) {

        int[] indegree = new int[V];

        // Step 1: Calculate indegree
        for (int u = 0; u < V; u++) {
            for (int v : adj.get(u)) {
                indegree[v]++;
            }
        }

        // Step 2: Push nodes with indegree 0
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }

        // Step 3: BFS
        int[] topo = new int[V];
        int idx = 0;

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

// ===================================================================

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
