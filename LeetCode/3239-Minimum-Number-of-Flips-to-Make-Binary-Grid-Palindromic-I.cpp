// 3239. Minimum Number of Flips to Make Binary Grid Palindromic I

class Solution {
public:

    int cntRow(vector<int>& a) {
        int m = a.size(), l = 0, r = m - 1, cnt = 0;
        while(l <= r) {
            if(a[l] != a[r]) cnt++;
            l++; r--;
        }
        return cnt;
    }

    int cntCol(vector<vector<int>>& grid, int c) {
        int n = grid.size(), l = 0, r = n - 1, cnt = 0;
        while(l <= r) {
            if(grid[l][c] != grid[r][c]) cnt++;
            l++; r--;
        }
        return cnt;
    }

    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), r = 0, c = 0;
        for(int i = 0; i < n; i++) {
            r += cntRow(grid[i]);
        }

        for(int i = 0; i < m; i++) {
            c += cntCol(grid, i);
        }
        return min(r, c);
    }
};
