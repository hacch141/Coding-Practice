class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	// Breath First Search (BFS)
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
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
	    vector<int> ans;
	    while(!q.empty()) {
	        int curr = q.front();
	        ans.push_back(curr);
	        q.pop();
	        for(auto it : adj[curr]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it);
	            }
	        }
	    }
	    return ans;
	}
	
	
    // Depth First Search (DFS)
    private:
    void dfs(int curr, int vis[], stack<int> &st, vector<int> adj[]) {
        vis[curr] = 1;
        for(auto it : adj[curr]) {
            if(!vis[it]) {
                dfs(it, vis, st, adj);
            }
        }
        st.push(curr);
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int vis[V] = {0};
	    stack<int> st;
	    for(int i=0; i<V; i++) {
	        if(!vis[i]) {
	            dfs(i, vis, st, adj);
	        }
	    }
	    
	    vector<int> ans;
	    while(!st.empty()) {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
