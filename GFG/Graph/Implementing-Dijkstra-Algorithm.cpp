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

// Using Set 
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> st;
        st.insert({0,S});
        vector<int> dist(V,1e9);
        dist[S] = 0;
        
        while(!st.empty()) {
            auto it = *(st.begin());
            int u = it.second;
            int d = it.first;
            st.erase(it);
            
            for(auto it : adj[u]) {
                int v = it[0];
                int weight = it[1];
                if(d+weight < dist[v]) {
                    if(dist[v] != 1e9) {
                        st.erase({dist[v],v});
                    }
                    dist[v] = d + weight;
                    st.insert({dist[v],v});
                }
            }
        }
        return dist;
    }
};
