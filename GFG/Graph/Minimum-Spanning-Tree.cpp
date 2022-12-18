class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> vis(V,0);
        pq.push({0,0});
        int ans = 0;
        
        while(!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            if(vis[u] == 1) continue;
            vis[u] = 1;
            ans += d;
            for(auto it : adj[u]) {
                int v = it[0];
                int weight = it[1];
                if(!vis[v]) pq.push({weight,v});
            }
        }
        return ans;
    }
};
