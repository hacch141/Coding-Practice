// Bipartite Graph

class Solution {
    public boolean solve(int u, int[][] graph, int[] color, int currColor) {
        color[u] = currColor;
        for (int v : graph[u]) {
            if (color[v] == -1) {
                if (!solve(v, graph, color, 1 - currColor)) return false;
            }
            else if (color[v] == color[u]) {
                return false;
            }
        }
        return true;
    }

    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n];
        Arrays.fill(color, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!solve(i, graph, color, 0)) return false;
            }
        }
        return true;
    }
}

// =====================================================================

// BFS
class Solution {
public:

    bool bfs(int start, int V, vector<int>adj[], vector<int>& col) {
        col[start] = 0;
        queue<int> q;
        q.push(start);
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto v : adj[u]) {
                if(col[v] == -1) {
                    col[v] = !col[u];
                    q.push(v);
                }
                else {
                    if(col[v] == col[u]) return false;
                }
            }
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> col(V,-1);
	    for(int i=0; i<V; i++) {
	        if(col[i] == -1) {
	            if(bfs(i,V,adj,col) == false) {
	                return false;
	            };
	        }
	    }
	    
	    return true;
	}

};

// T : O(V + 2*E)
// S : O(V)


// DFS
class Solution {
public:

    bool dfs(int u, vector<int>adj[], vector<int>& col, int currCol) {
        col[u] = currCol;
        
        for(auto v : adj[u]) {
            if(col[v] == -1) {
                if(dfs(v,adj,col,!currCol) == false) return false;
            }
            else {
                if(col[v] == col[u]) return false;
            }
        }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> col(V,-1);
	    for(int i=0; i<V; i++) {
	        if(col[i] == -1) {
	            if(dfs(i,adj,col,0) == false) {
	                return false;
	            };
	        }
	    }
	    
	    return true;
	}

};

// T : O(V + 2*E)
// S : O(V)
// S : O()
