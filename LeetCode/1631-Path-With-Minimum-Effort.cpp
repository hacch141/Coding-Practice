// 1631. Path With Minimum Effort

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});

        vector<int> dx = {+1, 0, -1, 0};
        vector<int> dy = {0, +1, 0, -1};

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int effort = curr[0], x = curr[1], y = curr[2];
            if(x == n - 1 && y == m - 1) return effort;
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int new_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));
                    if(new_effort < dist[nx][ny]) {
                        dist[nx][ny] = new_effort;
                        pq.push({dist[nx][ny], nx, ny});
                    }
                }
            }
        }

        return -1;
    }
};
