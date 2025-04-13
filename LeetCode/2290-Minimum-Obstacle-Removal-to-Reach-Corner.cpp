// 2290. Minimum Obstacle Removal to Reach Corner

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});

        vector<int> dx = {-1, 0, +1, 0};
        vector<int> dy = {0, +1, 0, -1};
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d1 = it[0];
            int x1 = it[1];
            int y1 = it[2];
            for(int k = 0; k < 4; k++) {
                int x2 = x1 + dx[k];
                int y2 = y1 + dy[k];
                if(x2 >= 0 && x2 < n && y2 >= 0 && y2 < m) {
                    int d2 = d1 + (grid[x2][y2] == 1);
                    if(d2 < dp[x2][y2]) {
                        dp[x2][y2] = d2;
                        pq.push({d2, x2, y2});
                    }
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};
