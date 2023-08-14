// Print shortest path

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
        
    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
        
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n+1,1e9), parent(n+1);

    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }

    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto it = pq.top();
        int u = it.second;
        int d = it.first;
        pq.pop();

        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({d + w, v});
                parent[v] = u;
            }
        }
    }

    // If distance to a node could not be found, return an array containing -1.
    if (dist[n] == 1e9) return {-1};

    vector<int> path;
    int node = n;

    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);

    reverse(path.begin(), path.end());
    return path;
}

// T : O(E * Log V)
// S : O(V + E)
