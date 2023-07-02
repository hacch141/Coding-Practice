// Print adjacency list

class Solution {
    // Function to return the adjacency list for each vertex.
    public ArrayList<ArrayList<Integer>> printGraph(int V, ArrayList<ArrayList<Integer>> adj) {

        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>(V);

        for (int i = 0; i < V; i++) {
            adjList.add(new ArrayList<>());
        }
        
        for (int i = 0; i < V; i++) {
            adjList.get(i).add(i);
            for (int j = 0; j < adj.get(i).size(); j++) {
                adjList.get(i).add(adj.get(i).get(j));
            }
        }
        return adjList;
    }
}

// T : O(V+E)
// S : O(V+E)
