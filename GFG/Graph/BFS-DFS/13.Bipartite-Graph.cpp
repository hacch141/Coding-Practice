// Bipartite Graph

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
