// 3459. Length of Longest V-Shaped Diagonal Segment

class Solution {
public:
    int N, M;
    vector<vector<int>> dir = {{-1, +1}, {+1, +1}, {+1, -1}, {-1, -1}};

    int solve(int i, int j, int d, vector<vector<int>>& grid, bool can_turn, int curr) {
        if(i < 0 || i >= N || j < 0 || j >= M || grid[i][j] != curr) return 0;
        int cnt = solve(i + dir[d][0], j + dir[d][1], d, grid, can_turn, curr == 2 ? 0 : 2);
        if(can_turn) {
            int nd = (d + 1) % 4;
            cnt = max(cnt, solve(i + dir[nd][0], j + dir[nd][1], nd, grid, false, curr == 2 ? 0 : 2));
        }
        return 1 + cnt;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        N = n, M = m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    for(int d = 0; d < 4; d++) {
                        ans = max(ans, 1 + solve(i + dir[d][0], j + dir[d][1], d, grid, true, 2));
                    }
                }
            }
        }
        return ans;
    }
};
