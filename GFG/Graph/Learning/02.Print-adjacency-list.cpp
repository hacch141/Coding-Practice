// Print adjacency list

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        // Code here
        vector<vector<int>> adjList(V);
        
        for(int i=0; i<V; i++) {
            adjList[i].push_back(i);
            for(auto next : adj[i]) {
                adjList[i].push_back(next);
            }
        }
        
        return adjList;
    }
};

// T : O(V+E)
// S : O(V+E)
