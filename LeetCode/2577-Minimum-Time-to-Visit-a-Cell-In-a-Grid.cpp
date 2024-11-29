// 2577. Minimum Time to Visit a Cell In a Grid

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        vector<int> dx = {0, -1, 0, +1}, dy = {-1, 0, +1, 0};
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int time = curr[0], x = curr[1], y = curr[2];
            if(x == n - 1 && y == m - 1) return time;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    int waitTime = ((grid[nx][ny] - time) % 2 == 0) ? 1 : 0;
                    int new_time = max(time + 1, grid[nx][ny] + waitTime);
                    vis[nx][ny] = true;
                    pq.push({new_time, nx, ny});

                }
            }
        }
        return -1;
    }
};
