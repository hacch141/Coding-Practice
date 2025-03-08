// 1514. Path with Maximum Probability

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> p(n, 0);
        priority_queue<pair<double, int>> pq;
        pq.push({1, start_node});
        p[start_node] = 1;

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int u = curr.second;
            double prob = curr.first;
            for(auto &it : adj[u]) {
                int v = it.first;
                double new_prob = prob * it.second;
                if(new_prob > p[v]) {
                    p[v] = new_prob;
                    pq.push({new_prob, v});
                }
            }
        }

        return p[end_node];
    }
};
