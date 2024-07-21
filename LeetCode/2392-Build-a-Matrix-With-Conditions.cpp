// 2392. Build a Matrix With Conditions

class Solution {
public:

    vector<int> topo(vector<vector<int>>& edges, int& k) {
        vector<int> indegree(k + 1, 0);
        vector<vector<int>> adj(k + 1);
        for(auto i : edges) {
            indegree[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }

        queue<int> q;
        for(int i = 1; i <= k; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> vec;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            vec.push_back(u);
            for(auto v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        return vec;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> r = topo(rowConditions, k);
        vector<int> c = topo(colConditions, k);
        if(c.size() != k || r.size() != k) return {};

        map<int,int> row, col;
        for(int i = 0; i < k; i++) {
            row[r[i]] = i;
            col[c[i]] = i;
        }
        vector<vector<int>> grid(k, vector<int>(k, 0));
        for(int i = 1; i <= k; i++) {
            grid[row[i]][col[i]] = i;
        }
        return grid;
    }
};
