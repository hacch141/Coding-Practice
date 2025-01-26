// Euler circuit and Path

// Undirected-Graph
class Solution {
public:
    void dfs(int u, vector<int>adj[], vector<bool>& vis) {
        vis[u] = true;
        for(auto &v : adj[u]) {
            if(!vis[v]) dfs(v, adj, vis);
        }
    }

    bool is_connected(int V, vector<int>adj[]) {
        int st = -1;
        for(int u = 0; u < V; u++) {
	        if(adj[u].size() > 0) {
	            st = u;
	            break;
	        }
	    }
	    
	    vector<bool> vis(V, false);
	    dfs(st, adj, vis);
	    
	    for(int u = 0; u < V; u++) {
	        if(!vis[u] && adj[u].size() > 0) {
	            return false;
	        }
	    }
	    
	    return true;
    }

	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	    
	    if(!is_connected(V, adj)) return 0;
	    
	    int cnt_odd = 0;
	    for(int u = 0; u < V; u++) {
	        cnt_odd += adj[u].size() % 2;
	    }
	    if(cnt_odd == 0) return 2;
	    else if(cnt_odd == 2) return 1;
	    return 0;
	}
};
