// 3070. Count Submatrices with Top-Left Element and Sum Less Than k

class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prefix.resize(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                prefix[i][j] = matrix[i][j];
                if(i - 1 >= 0) prefix[i][j] += prefix[i - 1][j];
                if(j - 1 >= 0) prefix[i][j] += prefix[i][j - 1];
                if(i - 1 >= 0 && j - 1 >= 0) prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = prefix[row2][col2];
        if(row1-1 >= 0) ans -= prefix[row1-1][col2];
        if(col1-1 >= 0) ans -= prefix[row2][col1-1];
        if(row1-1 >= 0 && col1-1 >= 0) ans += prefix[row1-1][col1-1];
        return ans;
    }
};

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        NumMatrix M(grid);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans += M.sumRegion(0, 0, i, j) <= k;
            }
        }
        return ans;
    }
};
