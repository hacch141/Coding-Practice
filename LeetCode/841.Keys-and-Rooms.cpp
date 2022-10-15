// 841. Keys and Rooms

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        q.push(0);
        vector<int> visited(n,0);
        visited[0] = 1;
        
        while(q.empty() == false) {
            int r = q.front();
            q.pop();
            for(auto i : rooms[r]) {
                if(visited[i] == 0) {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
        
        for(auto i : visited) {
            if(i == 0) {
                return false;
            }
        }
        return true;
    }
};
