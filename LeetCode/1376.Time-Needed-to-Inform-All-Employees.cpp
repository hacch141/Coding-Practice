// 1376. Time Needed to Inform All Employees

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        int M;
        for(int i=0; i<n; i++) {
            if(manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
            else {
                M = i;
            }
        }

        int time = 0;
        queue<pair<int,int>> q;
        q.push({M,0});
        while(!q.empty()) {
            int u = q.front().first;
            int currtime = q.front().second;
            time = max(time,q.front().second);
            q.pop();
            for(auto v : adj[u]) {
                q.push({v,informTime[u]+currtime});
            }
        }

        return time;
    }
};
