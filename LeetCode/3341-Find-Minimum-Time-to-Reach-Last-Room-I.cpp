// 3341. Find Minimum Time to Reach Last Room I

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        moveTime[0][0] = -1;

        vector<int> dx = {-1, 0, +1, 0};
        vector<int> dy = {0, +1, 0, -1};

        while(!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int t1 = v[0], x1 = v[1], y1 = v[2];
            if(x1 == n - 1 && y1 == m - 1) return t1;
            for(int x = 0; x < 4; x++) {
                int x2 = x1 + dx[x];
                int y2 = y1 + dy[x];
                if(x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && moveTime[x2][y2] != -1) {
                    int t2 = 1 + max(t1, moveTime[x2][y2]);
                    pq.push({t2, x2, y2});
                    moveTime[x2][y2] = -1;
                }
            }
        }

        return -1;
    }
};
