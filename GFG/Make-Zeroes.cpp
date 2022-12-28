class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>> v;
        vector<vector<int> > duplicate = matrix;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    v.push_back({i,j});
                }
            }
        }
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        for(auto it : v) {
            int add = 0;
            for(int i=0; i<4; i++) {
                int nRow = delRow[i] + it.first;
                int nCol = delCol[i] + it.second;
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m) {
                    add += duplicate[nRow][nCol];
                    matrix[nRow][nCol] = 0;
                }
            }
            matrix[it.first][it.second] = add;
        }
    }
};
