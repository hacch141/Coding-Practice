// 3446. Sort Matrix by Diagonals

class Solution {
public:
    void help(int x, int y, vector<vector<int>>& grid, int& n, bool inc) {
        vector<int> v;
        int i = x, j = y;
        while(i < n && j < n) {
            v.push_back(grid[i][j]);
            i++; j++;
        }

        if(inc) sort(v.begin(), v.end());
        else sort(v.rbegin(), v.rend());

        i = x, j = y;
        for(int k = 0; k < v.size(); k++) {
            grid[i][j] = v[k];
            i++; j++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            help(i, 0, grid, n, false);
        }
        for(int j = 1; j < n; j++) {
            help(0, j, grid, n, true);
        }
        return grid;
    }
};
