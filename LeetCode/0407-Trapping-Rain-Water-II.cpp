// 407. Trapping Rain Water II

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size();

        if(n <= 2 || m <= 2) return 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {
            pq.push({heightMap[i][0], i, 0});
            vis[i][0] = true;
            pq.push({heightMap[i][m - 1], i, m - 1});
            vis[i][m - 1] = true;
        }
        
        for(int j = 0; j < m; j++) {
            pq.push({heightMap[0][j], 0, j});
            vis[0][j] = true;
            pq.push({heightMap[n - 1][j], n - 1, j});
            vis[n - 1][j] = true;
        }

        vector<int> dx = {+1, 0, -1, 0};
        vector<int> dy = {0, +1, 0, -1};

        int trapped_water = 0;
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int h = curr[0], x = curr[1], y = curr[2];
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    trapped_water += max(0, h - heightMap[nx][ny]);
                    pq.push({max(h, heightMap[nx][ny]), nx, ny});
                }
            }
        }

        return trapped_water;
    }
};
