// 2257. Count Unguarded Cells in the Grid

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, '.'));
        for(auto i : guards) grid[i[0]][i[1]] = 'G';
        for(auto i : walls) grid[i[0]][i[1]] = 'W';
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(auto g : guards) {
            int i = g[0], j = g[1];
            int l = j - 1, r = j + 1;
            while(l >= 0 && grid[i][l] == '.') {
                vis[i][l] = true;
                l--;
            }
            while(r < n && grid[i][r] == '.') {
                vis[i][r] = true;
                r++;
            }
            int t = i - 1, b = i + 1;
            while(t >= 0 && grid[t][j] == '.') {
                vis[t][j] = true;
                t--;
            }
            while(b < m && grid[b][j] == '.') {
                vis[b][j] = true;
                b++;
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && grid[i][j] == '.') ans++;
            }
        }

        return ans;
    }
};
