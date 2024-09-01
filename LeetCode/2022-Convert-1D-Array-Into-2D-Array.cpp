// 2022. Convert 1D Array Into 2D Array

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len = original.size();
        if(m * n != len) return {};
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < len; i++) {
            int x = i / n;
            int y = i % n;   
            grid[x][y] = original[i];
        }
        return grid;
    }
};
