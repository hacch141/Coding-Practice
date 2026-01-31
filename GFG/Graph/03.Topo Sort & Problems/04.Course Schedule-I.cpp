// Course Schedule - I

class Solution {
    public boolean isPossible(int N, int[][] prerequisites) {
        // create adj[]
        ArrayList<Integer>[] adj = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            adj[i] = new ArrayList<>();
        }

        int[] indegree = new int[N];

        // build graph
        for (int[] p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].add(course);
            indegree[course]++;
        }

        // Kahn's Algorithm
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }

        int cnt = 0;
        while (!q.isEmpty()) {
            int u = q.poll();
            cnt++;

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.offer(v);
                }
            }
        }

        return cnt == N;
    }
}

// ===============================================================================

// BFS
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>> adj(N);
	    vector<int> indegree(N,0);
	    
	    for(auto i : prerequisites) {
	        adj[i.second].push_back(i.first);
	        indegree[i.first]++;
	    }
	    
	    queue<int> q;
	    for(int i=0; i<N; i++) {
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
	    
	    return cnt == N;
	}
};

// T : O(V + 2*E)
// S : O(V)


// DFS
class Solution {
    
private:
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathvis, int& cnt) {
        vis[u] = 1;
        pathvis[u] = 1;
        
        for(auto v : adj[u]) {
            if(!vis[v]) {
                if(dfs(v,adj,vis,pathvis,cnt) == false) return false;
            }
            else if(pathvis[v]) {
                return false;
            }
        }
        
        pathvis[u] = 0;
        cnt++;
        return true;
    }
    
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>> adj(N);
	    vector<int> vis(N,0);
	    vector<int> pathvis(N,0);
	    
	    for(auto i : prerequisites) {
	        adj[i.second].push_back(i.first);
	    }
	    
	    int cnt = 0;
	    for(int i=0; i<N; i++) {
	        if(!vis[i]) {
	            if(dfs(i,adj,vis,pathvis,cnt) == false) {
	                return false;
	            }
	        }
	    }
	    
	    return cnt == N;
	}
};

// T : O(V + 2*E)
// S : O(V)
