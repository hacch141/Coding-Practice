// 2050. Parallel Courses III

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto &it : relations) {
            adj[it[0] - 1].push_back(it[1] - 1);
            indegree[it[1] - 1]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                pq.push({time[i], i});
            }
        }

        int total_time = 0;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int t = it.first;
            int u = it.second;
            total_time = t;
            for(auto &v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    pq.push({t + time[v], v});
                }
            }
        }

        return total_time;
    }
};
