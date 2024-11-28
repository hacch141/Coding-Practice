// 2290. Minimum Obstacle Removal to Reach Corner

class Solution {
public:
    int dijkstra(vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        vis[0][0] = true;
        pq.push({grid[0][0], {0, 0}});
        vector<int> dx = {-1, 0, +1, 0}, dy = {0, +1, 0, -1};
        while(!pq.empty()) {
            int cnt_obs = pq.top().first, x = pq.top().second[0], y = pq.top().second[1];
            if(x == n - 1 && y == m - 1) return cnt_obs;
            pq.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({cnt_obs + grid[nx][ny], {nx, ny}});
                }
            }
        }
        return -1;
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        return dijkstra(grid, vis);
    }
};
