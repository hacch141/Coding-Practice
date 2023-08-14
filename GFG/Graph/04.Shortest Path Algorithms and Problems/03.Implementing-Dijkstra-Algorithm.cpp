// Implementing Dijkstra Algorithm

// Using Priority Queue
vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    // Write your code here.
    // 'edge' contains {u, v, distance} vectors.
    vector<vector<pair<int,int>>> adj(vertices);
    for(auto i : edge) {
        int u = i[0];
        int v = i[1];
        int w = i[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push({0,source});

    vector<int> dist(vertices,1e9);
    dist[source] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        for(auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if(d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v],v});
            }
        }
    }

    return dist;
}

// T : O((V + 2*E) * LogV)
// S : O(V)



// Using Set
vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    // Write your code here.
    // 'edge' contains {u, v, distance} vectors.
    vector<vector<pair<int,int>>> adj(vertices);
    for(auto i : edge) {
        int u = i[0];
        int v = i[1];
        int w = i[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    set<pair<int,int>> st;
    st.insert({0,source});

    vector<int> dist(vertices,1e9);
    dist[source] = 0;

    while(!st.empty()) {
        auto i = *(st.begin());
        int u = i.second;
        int d = i.first;
        st.erase(i);
        for(auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if(d + w < dist[v]) {
                if(dist[v] != 1e9) {
                    st.erase({dist[v],v});
                }
                dist[v] = d + w;
                st.insert({dist[v],v});
            }
        }
    }

    return dist;
}

// T : O((V + 2*E) * LogV)
// S : O(V)
