// 1091. Shortest Path in Binary Matrix

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        vector<int> dx = {+1, 0, -1, 0, +1, +1, -1, -1};
        vector<int> dy = {0, +1, 0, -1, +1, -1, +1, -1};

        queue<pair<int,int>> q;
        q.push({0, 0});

        set<pair<int,int>> vis;
        vis.insert({0, 0});

        int cells = 1;
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                auto curr = q.front();
                q.pop();
                int x = curr.first, y = curr.second;
                if(x == n - 1 && y == n - 1) return cells;
                for(int k = 0; k < 8; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && !vis.count({nx, ny})) {
                        q.push({nx, ny});
                        vis.insert({nx, ny});
                    }
                }
            }
            cells++;
        }

        return -1;
    }
};
