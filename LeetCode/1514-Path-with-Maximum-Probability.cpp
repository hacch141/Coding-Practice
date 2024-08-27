// 1514. Path with Maximum Probability

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        int len = edges.size();
        vector<vector<pair<int,double>>> adj(n);
        for(int i = 0; i < len; i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }

        vector<double> p(n, 0);
        p[start_node] = 1;

        priority_queue<pair<double,int>> pq;
        pq.push({1, start_node});

        while(!pq.empty()) {
            int u = pq.top().second;
            double pu = pq.top().first;
            if(u == end_node) return pu;
            pq.pop();
            for(auto it : adj[u]) {
                int v = it.first;
                double pv = it.second;
                if(pu * pv > p[v]) {
                    p[v] = pu * pv;
                    pq.push({p[v], v});
                }
            }
        }

        return p[end_node];
    }
};
