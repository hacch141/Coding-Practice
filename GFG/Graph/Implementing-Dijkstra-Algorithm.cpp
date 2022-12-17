// Using priority Queue
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,S});
        vector<int> dist(V,1e9);
        dist[S] = 0;
        while(!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            for(auto it : adj[u]) {
                int v = it[0];
                int weight = it[1];
                if(d + weight < dist[v]) {
                    dist[v] = d + weight;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};
