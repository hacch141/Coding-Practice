// Implementing Dijkstra Algorithm

// Using Priority Queue
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,1e9);
        dist[S] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({S,0});
        
        while(!pq.empty()) {
            int u = pq.top().first;
            pq.pop();
            
            for(auto it : adj[u]) {
                int v = it[0];
                int w = it[1];
                if(w + dist[u] < dist[v]) {
                    dist[v] = w + dist[u];
                    pq.push({v,dist[v]});
                }
            }
        }
        
        return dist;
    }
};

// T : O((V + 2*E) * LogV)
// S : O(V)

// Using Set
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,1e9);
        dist[S] = 0;
        
        set<pair<int,int>> st;
        st.insert({S,0});
        
        while(!st.empty()) {
            auto it = *(st.begin());
            int u = it.first;
            st.erase(it);
            
            for(auto it : adj[u]) {
                int v = it[0];
                int w = it[1];
                if(w + dist[u] < dist[v]) {
                    dist[v] = w + dist[u];
                    st.insert({v,dist[v]});
                }
            }
        }
        
        return dist;
    }
};

// T : O((V + 2*E) * LogV)
// S : O(V)
