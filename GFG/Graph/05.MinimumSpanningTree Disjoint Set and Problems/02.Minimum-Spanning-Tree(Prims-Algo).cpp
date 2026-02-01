// Minimum Spanning Tree

// Prims Algorithm
class Solution {
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    public int spanningTree(int V, ArrayList<int[]>[] adj) {

        // min-heap: {weight, node}
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        boolean[] vis = new boolean[V];

        pq.offer(new int[]{0, 0}); // {weight, startNode}
        int sum = 0;

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int wt = cur[0];
            int u = cur[1];

            if (vis[u]) continue;

            vis[u] = true;
            sum += wt;

            for (int[] it : adj[u]) {
                int v = it[0];
                int newWt = it[1];
                if (!vis[v]) {
                    pq.offer(new int[]{newWt, v});
                }
            }
        }

        return sum;
    }
}

// ==========================================================================

// Prims Algorithm
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> vis(V,0);
        
        int sum = 0;
        while(!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(vis[u]) {
                continue;
            }
            sum += d;
            vis[u] = 1;
            for(auto it : adj[u]) {
                int v = it[0];
                int newd = it[1];
                if(!vis[v]) pq.push({newd,v});
            }
        }
        
        return sum;
    }
};

// T : O(E * LogV)
// S : O(V + E)
