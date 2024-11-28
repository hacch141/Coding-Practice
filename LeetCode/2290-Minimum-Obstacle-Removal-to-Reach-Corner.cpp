// 2290. Minimum Obstacle Removal to Reach Corner

class Solution {
public:
    void dijkstra(vector<vector<int>>& grid, vector<vector<int>>& dp, vector<vector<bool>>& vis) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        vis[0][0] = true;
        dp[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        vector<int> dx = {-1, 0, +1, 0};
        vector<int> dy = {0, +1, 0, -1};
        while(!pq.empty()) {
            int cnt_obs = pq.top().first, x = pq.top().second[0], y = pq.top().second[1];
            pq.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && (!vis[nx][ny] || dp[x][y] + grid[nx][ny] < dp[nx][ny])) {
                    vis[nx][ny] = true;
                    dp[nx][ny] = dp[x][y] + grid[nx][ny];
                    pq.push({dp[nx][ny], {nx, ny}});
                }
            }
        }
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dijkstra(grid, dp, vis);
        return dp[n - 1][m - 1];
    }
};
