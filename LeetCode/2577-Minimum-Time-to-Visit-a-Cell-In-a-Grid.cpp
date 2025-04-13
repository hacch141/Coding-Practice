// 2577. Minimum Time to Visit a Cell In a Grid

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        time[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});

        vector<int> dx = {-1, 0, +1, 0};
        vector<int> dy = {0, +1, 0, -1};

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int t1 = it[0];
            int x1 = it[1];
            int y1 = it[2];
            for(int k = 0; k < 4; k++) {
                int x2 = x1 + dx[k];
                int y2 = y1 + dy[k];
                if(x2 >= 0 && x2 < n && y2 >= 0 && y2 < m) {
                    int t2 = grid[x2][y2] <= time[x1][y1] ? 1 + time[x1][y1] : grid[x2][y2] + (time[x1][y1] % 2 == grid[x2][y2] % 2);
                    if(t2 < time[x2][y2]) {
                        time[x2][y2] = t2;
                        pq.push({t2, x2, y2});
                    }
                }
            }
        }

        return time[n - 1][m - 1];
    }
};
