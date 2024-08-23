// 3240. Minimum Number of Flips to Make Binary Grid Palindromic II

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;

        int t = 0, b = n - 1;
        while(t < b) {
            int l = 0, r = m - 1;
            while(l < r) {
                int sum = grid[t][l] + grid[t][r] + grid[b][l] + grid[b][r];
                if(sum != 0 && sum != 4) ans += (sum == 2) ? 2 : 1;
                l++, r--;
            }
            t++; b--;
        }

        int c11 = 0, c01 = 0;
        if(n & 1) {
            int row = n / 2, l = 0, r = m - 1;
            while(l < r) {
                if(grid[row][l] == grid[row][r]) {
                    c11 += grid[row][l] == 1;
                }
                else {
                    c01++;
                }
                l++; r--;
            }
        }

        if(m & 1) {
            int col = m / 2, l = 0, r = n - 1;
            while(l < r) {
                if(grid[l][col] == grid[r][col]) {
                    c11 += grid[l][col] == 1;
                }
                else {
                    c01++;
                }
                l++; r--;
            }
        }

        if((c11 & 1) && c01 == 0) ans += 2;
        ans += c01;

        if((n & 1) && (m & 1)) {
            ans += grid[n / 2][m / 2];
        }

        return ans;
    }
};
