// Shortest path in a binary maze

class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;

        // If start or end is blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        // BFS queue: {x, y}
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{0, 0});

        // mark visited
        grid[0][0] = 1;

        int lvl = 1;

        int[] dx = {0, 1, 0, -1, 1, 1, -1, -1};
        int[] dy = {1, 0, -1, 0, 1, -1, -1, 1};

        while (!q.isEmpty()) {
            int sz = q.size();

            while (sz-- > 0) {
                int[] cur = q.poll();
                int x = cur[0];
                int y = cur[1];

                if (x == n - 1 && y == n - 1) return lvl;

                for (int k = 0; k < 8; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && nx < n &&
                        ny >= 0 && ny < n &&
                        grid[nx][ny] == 0) {

                        q.offer(new int[]{nx, ny});
                        grid[nx][ny] = 1; // mark visited
                    }
                }
            }
            lvl++;
        }

        return -1;
    }
}

// ============================================================================

// Normal BFS
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        queue<pair<int,int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int lvl = 1;

        vector<int> dx = {0, +1, 0, -1, +1, +1, -1, -1};
        vector<int> dy = {+1, 0, -1, 0, +1, -1, -1, +1};

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto it = q.front();
                q.pop();
                int x = it.first, y = it.second;
                if(x == n - 1 && y == n - 1) return lvl;
                for(int k = 0; k < 8; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        q.push({nx, ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
            lvl++;
        }

        return -1;
    }
};

// T : O(N*M)
// S : O(N*M)
