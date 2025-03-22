// 2642. Design Graph With Shortest Path Calculator

class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    int N;

    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        adj.resize(n);
        for(auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }
    }

    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, node1});

        vector<int> dist(N, INT_MAX);
        dist[node1] = 0;

        while(!pq.empty()) {
            auto curr = pq.top();
            int d = curr.first;
            int u = curr.second;
            pq.pop();
            for(auto &it : adj[u]) {
                int v = it.first;
                int next_d = it.second;
                if(d + next_d < dist[v]) {
                    dist[v] = d + next_d;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[node2] != INT_MAX ? dist[node2] : -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
