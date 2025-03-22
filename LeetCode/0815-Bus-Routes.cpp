// 815. Bus Routes

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;

        int n = routes.size();
        map<int,vector<int>> stop_to_bus;
        for(int i = 0; i < n; i++) {
            for(auto &s : routes[i]) {
                stop_to_bus[s].push_back(i);
            }
        }

        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            set<int> buses;
            for(auto &s : routes[i]) {
                for(auto &b : stop_to_bus[s]) {
                    buses.insert(b);
                }
            }
            for(auto &b : buses) {
                adj[i].push_back(b);
            }
        }

        queue<int> q;
        vector<bool> vis(n, false);
        for(auto &b : stop_to_bus[source]) {
            q.push(b);
            vis[b] = true;
        }

        set<int> target_buses;
        for(auto &b : stop_to_bus[target]) {
            target_buses.insert(b);
        }

        int ans = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int u = q.front();
                q.pop();
                if(target_buses.count(u)) return ans;
                for(auto &v : adj[u]) {
                    if(!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};

// ================================================================

// code with MIK
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> adj;
        
        for (int route = 0; route < routes.size(); route++) {
            for (auto stop : routes[route]) {
                adj[stop].push_back(route);
            }
        }

        queue<int> que;
        vector<bool> visited(501, false);
        
        for (auto route : adj[source]){
            que.push(route);
            visited[route] = true;
        }

        int busCount = 1;
        while (!que.empty()) {
            int size = que.size();

            while(size--) {
                int route = que.front();
                que.pop();

                
                for (auto &stop: routes[route]) {
                    
                    if (stop == target) {
                        return busCount;
                    }

                    
                    for (auto nextRoute : adj[stop]) {
                        if (!visited[nextRoute]) {
                            visited[nextRoute] = true;
                            que.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};
