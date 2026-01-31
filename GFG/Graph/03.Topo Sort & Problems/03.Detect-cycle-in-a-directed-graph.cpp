// Detect cycle in a directed graph

import java.util.*;

class Solution {

    // Function to detect cycle in a directed graph
    public boolean isCyclic(int V, List<List<Integer>> adj) {

        int[] indegree = new int[V];

        // Step 1: Compute indegree
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

        // Step 3: BFS (Kahn’s Algorithm)
        int cnt = 0;

        while (!q.isEmpty()) {
            int u = q.poll();
            cnt++;

            for (int v : adj.get(u)) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.offer(v);
                }
            }
        }

        // If not all nodes are processed, cycle exists
        return cnt != V;
    }
}

// =================================================================

// BFS-TOPO
class Solution {
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
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
        
        int cnt = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;
            for(auto v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return cnt != V;
    }
};

// T : O(V + 2*E)
// S : O(V)
