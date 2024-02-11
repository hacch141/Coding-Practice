// 3033. Modify the Matrix

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int mx, n = matrix.size(), m = matrix[0].size();
        for(int j = 0; j < m; j++) {
            mx = 0;
            for(int i = 0; i < n; i++) {
                mx = max(mx, matrix[i][j]);
            }
            for(int i = 0; i < n; i++) {
                if(matrix[i][j] == -1) matrix[i][j] = mx;
            }
        }
        return matrix;
    }
};
