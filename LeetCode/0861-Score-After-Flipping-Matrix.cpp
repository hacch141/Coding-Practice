// 861. Score After Flipping Matrix

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < m; j++) grid[i][j] = 1 - grid[i][j];
            }
        }

        for(int j = 0; j < m; j++) {
            int c = 0;
            for(int i = 0; i < n; i++) {
                c += grid[i][j];
            }
            c = max(c, n - c);
            cout << c << endl;
            ans += (1 << (m - 1 - j)) * c;
        }

        return ans;
    }
};
