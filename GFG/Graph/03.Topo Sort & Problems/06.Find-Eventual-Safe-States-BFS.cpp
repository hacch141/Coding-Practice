// Eventual Safe States

class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int V = graph.length;

        // indegree = outdegree in original graph
        int[] indegree = new int[V];

        // reverse graph
        ArrayList<Integer>[] revAdj = new ArrayList[V];
        for (int i = 0; i < V; i++) {
            revAdj[i] = new ArrayList<>();
        }

        // build reverse graph and indegree
        for (int u = 0; u < V; u++) {
            for (int v : graph[u]) {
                revAdj[v].add(u);
                indegree[u]++;
            }
        }

        // queue for terminal nodes
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }

        List<Integer> ans = new ArrayList<>();

        // Kahn's Algorithm
        while (!q.isEmpty()) {
            int u = q.poll();
            ans.add(u);

            for (int v : revAdj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.offer(v);
                }
            }
        }

        Collections.sort(ans);
        return ans;
    }
}

// =============================================================

// BFS
class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree(V,0);
        vector<int> adjRev[V];
        
        for(int u=0; u<V; u++) {
            for(auto v : adj[u]) {
                adjRev[v].push_back(u);
                indegree[u]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(auto v : adjRev[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};


// T : O(V + 2*E)
// S : O(O(VlogV + E)


// DFS
class Solution {
    
  private:
    bool dfs(int u, vector<int> adj[], vector<int>& vis, vector<int>& pathvis, vector<int>& safe) {
        vis[u] = 1;
        pathvis[u] = 1;
        
        for(auto v: adj[u]) {
            if(!vis[v]) {
                if(dfs(v,adj,vis,pathvis,safe) == false) return false;
            }
            else if(pathvis[v]) {
                return false;
            }
        }
        
        pathvis[u] = 0;
        safe[u] = 1;
        return true;
    }
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        vector<int> safe(V,0);
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(i,adj,vis,pathvis,safe);
            }
        }
        
        vector<int> ans;
        for(int i=0; i<V; i++) {
            if(safe[i]) ans.push_back(i);
        }
        
        return ans;
    }
};

// dfs
class Solution {

    private boolean dfs(int u, int[][] graph, boolean[] vis, boolean[] pathVis, boolean[] safe) {
        vis[u] = true;
        pathVis[u] = true;

        for (int v : graph[u]) {
            if (!vis[v]) {
                if (!dfs(v, graph, vis, pathVis, safe)) {
                    return false;
                }
            } else if (pathVis[v]) {
                // cycle detected
                return false;
            }
        }

        pathVis[u] = false;
        safe[u] = true;   // no cycle reachable from u
        return true;
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {

        int V = graph.length;

        boolean[] vis = new boolean[V];
        boolean[] pathVis = new boolean[V];
        boolean[] safe = new boolean[V];

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pathVis, safe);
            }
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            if (safe[i]) {
                ans.add(i);
            }
        }

        return ans;
    }
}


// T : O(V + 2*E)
// S : O(V)
