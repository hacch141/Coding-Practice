// Detect cycle in a directed graph

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    // by using Topological Sort
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int indegree[V] = {0};
        for(int i=0; i<V; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
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
            int curr = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[curr]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return cnt != V;
    }
};
