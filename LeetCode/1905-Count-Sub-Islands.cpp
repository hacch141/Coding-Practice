// 1905. Count Sub Islands

class Solution {
public:

    bool dfs(int r, int c, int& n, int& m, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& vis) {
        if(r < 0 || r >= n || c < 0 || c >= m || grid2[r][c] == 0 || vis[r][c]) return true;
        vis[r][c] = true;
        bool f = grid1[r][c] == grid2[r][c];
        f &= dfs(r + 1, c, n, m, grid1, grid2, vis);
        f &= dfs(r, c + 1, n, m, grid1, grid2, vis);
        f &= dfs(r - 1, c, n, m, grid1, grid2, vis);
        f &= dfs(r, c - 1, n, m, grid1, grid2, vis);
        return f;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size(), ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid2[i][j] == 1 && !vis[i][j] && dfs(i, j, n, m, grid1, grid2, vis)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
