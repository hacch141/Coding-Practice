// 3242. Design Neighbor Sum Service

class NeighborSum {

private:
    vector<vector<int>> grid;
    map<int,pair<int,int>> mp;
    int n;

public:
    NeighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        this->grid = grid;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                this->mp[grid[i][j]] = {i, j};
            }
        }
    }
    
    int adjacentSum(int value) {
        int sum = 0;
        auto [r, c] = mp[value];
        if(r - 1 >= 0) sum += grid[r - 1][c];
        if(c - 1 >= 0) sum += grid[r][c - 1];
        if(r + 1 < n)  sum += grid[r + 1][c];
        if(c + 1 < n)  sum += grid[r][c + 1];
        return sum;
    }
    
    int diagonalSum(int value) {
        int sum = 0;
        auto [r, c] = mp[value];
        if(r - 1 >= 0 && c - 1 >= 0) sum += grid[r - 1][c - 1];
        if(r - 1 >= 0 && c + 1 < n)  sum += grid[r - 1][c + 1];
        if(r + 1 < n && c + 1 < n)   sum += grid[r + 1][c + 1];
        if(r + 1 < n && c - 1 >= 0)  sum += grid[r + 1][c - 1];
        return sum;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
