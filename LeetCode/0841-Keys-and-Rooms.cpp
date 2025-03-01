// 841. Keys and Rooms

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        queue<int> q;
        for(auto &i : rooms[0]) q.push(i);
        vector<bool> vis(n, false);
        vis[0] = true;

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int u = q.front();
                q.pop();
                vis[u] = true;
                for(auto &v : rooms[u]) {
                    if(!vis[v]) q.push(v);
                }
            }
        }

        bool f = true;
        for(auto i : vis) f &= i;

        return f;
    }
};
