// 304. Range Sum Query 2D - Immutable

class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = matrix.size();
        int m = matrix[0].size();
        prefix = matrix;
        for(int i=0; i<n; i++) {
            for(int j=1; j<m; j++) {
                prefix[i][j] = prefix[i][j-1] + matrix[i][j];
            }
        }

        for(int j=0; j<m; j++) {
            for(int i=1; i<n; i++) {
                prefix[i][j] = prefix[i][j] + prefix[i-1][j];
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

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
