// Number of Provinces

class Solution {
    List<Integer>[] adj;

    public void dfs(int u, boolean[] vis) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v, vis);
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;

        adj = new ArrayList[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].add(j);
                }
            }
        }

        int cnt = 0;
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, vis);
            }
        }

        return cnt;
    }
}

// ==================================================================

class Solution {
    
  private:
    void dfs(int node, vector<int> adjList[], int vis[]) {
        vis[node] = 1;
        for(auto it : adjList[node]) {
            if(!vis[it]) {
                dfs(it, adjList, vis);
            }
        }
    }
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adjList[V];
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(adj[i][j] == 1 && i!=j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
      
        int cnt = 0;
        int vis[V] = {0};
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, adjList, vis);
            }
        }
        return cnt;
    }
};

// T : O (V + 2*E)
// S : O (V)
