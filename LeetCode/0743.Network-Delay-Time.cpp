// 743. Network Delay Time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i : times) {
            adj[i[0]].push_back({i[1],i[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> time(n+1,1e9);
        time[k] = 0;

        while(!pq.empty()) {
            int u = pq.top().second;
            int ut = pq.top().first;
            pq.pop();

            for(auto it : adj[u]) {
                int v = it.first;
                int vt = it.second;
                if(ut + vt < time[v]) {
                    time[v] = ut + vt;
                    pq.push({time[v],v});
                }
            }
        }

        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(time[i] == 1e9) {
                return -1;
            }
            ans = max(ans,time[i]);
        }

        return ans;
    }
};
