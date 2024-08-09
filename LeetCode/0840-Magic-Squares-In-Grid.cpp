// 840. Magic Squares In Grid
class Solution {
public:

    bool ok(int r, int c, vector<vector<int>>& grid) {
        vector<int> f(10, 0);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int ele = grid[r + i][c + j]; 
                if(ele >= 1 && ele <= 9) f[ele]++;
            }
        }

        for(int i = 1; i <= 9; i++) if(f[i] != 1) return false;

        int sum = 0;
        for(int i = 0; i < 3; i++) sum += grid[r][c + i];


        // check rows
        for(int i = 0; i < 3; i++) {
            int curr = 0;
            for(int j = 0; j < 3; j++) {
                curr += grid[r + i][c + j];
            }
            if(curr != sum) return false;
        }

        // check cols
        for(int j = 0; j < 3; j++) {
            int curr = 0;
            for(int i = 0; i < 3; i++) {
                curr += grid[r + i][c + j];
            }
            if(curr != sum) return false;
        }

        // check diagonals
        int dg1 = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
        int dg2 = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];
        if(dg1 != sum || dg2 != sum) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < m - 2; j++) {
                if(ok(i, j, grid)) ans++;
            }
        }
        return ans;
    }
};
