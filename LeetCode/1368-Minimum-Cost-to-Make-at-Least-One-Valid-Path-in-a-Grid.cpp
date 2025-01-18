// 1368. Minimum Cost to Make at Least One Valid Path in a Grid

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<int> dx = {0, 0, +1, -1};
        vector<int> dy = {+1, -1, 0, 0};

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        pq.push({0, 0, 0});
        dist[0][0] = 0;

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int w = curr[0], i = curr[1], j = curr[2];
            if(i == n - 1 && j == m - 1) return w;

            for(int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int nw = w + (grid[i][j] != k + 1);
                    if(nw < dist[ni][nj]) {
                        dist[ni][nj] = nw;
                        pq.push({nw, ni, nj});
                    }
                }
            }
        }

        return 0;
    }
};
