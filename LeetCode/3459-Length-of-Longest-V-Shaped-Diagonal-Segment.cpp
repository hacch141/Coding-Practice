// 3459. Length of Longest V-Shaped Diagonal Segment

class Solution {
public:
    int N, M;
    int top_right(int i, int j, vector<vector<int>>& grid, bool can_turn, int curr) {
        if(i < 0 || i >= N || j < 0 || j >= M || grid[i][j] != curr) return 0;
        int cnt = top_right(i - 1, j + 1, grid, can_turn, curr == 2 ? 0 : 2);
        if(can_turn) cnt = max(cnt, bottom_right(i + 1, j + 1, grid, false, curr == 2 ? 0 : 2));
        return cnt + 1;
    }

    int bottom_right(int i, int j, vector<vector<int>>& grid, bool can_turn, int curr) {
        if(i < 0 || i >= N || j < 0 || j >= M || grid[i][j] != curr) return 0;
        int cnt = bottom_right(i + 1, j + 1, grid, can_turn, curr == 2 ? 0 : 2);
        if(can_turn) cnt = max(cnt, bottom_left(i + 1, j - 1, grid, false, curr == 2 ? 0 : 2));
        return cnt + 1;
    }

    int bottom_left(int i, int j, vector<vector<int>>& grid, bool can_turn, int curr) {
        if(i < 0 || i >= N || j < 0 || j >= M || grid[i][j] != curr) return 0;
        int cnt = bottom_left(i + 1, j - 1, grid, can_turn, curr == 2 ? 0 : 2);
        if(can_turn) cnt = max(cnt, top_left(i - 1, j - 1, grid, false, curr == 2 ? 0 : 2));
        return cnt + 1;
    }

    int top_left(int i, int j, vector<vector<int>>& grid, bool can_turn, int curr) {
        if(i < 0 || i >= N || j < 0 || j >= M || grid[i][j] != curr) return 0;
        int cnt = top_left(i - 1, j - 1, grid, can_turn, curr == 2 ? 0 : 2);
        if(can_turn) cnt = max(cnt, top_right(i - 1, j + 1, grid, false, curr == 2 ? 0 : 2));
        return cnt + 1;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        N = n, M = m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    ans = max(ans, 1 + top_right(i - 1, j + 1, grid, true, 2));
                    ans = max(ans, 1 + bottom_right(i + 1, j + 1, grid, true, 2));
                    ans = max(ans, 1 + bottom_left(i + 1, j - 1, grid, true, 2));
                    ans = max(ans, 1 + top_left(i - 1, j - 1, grid, true, 2));
                }
            }
        }
        return ans;
    }
};
