class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int firstCol = 0;
        int firstRow = 0;

        for(int i=0; i<n; i++) {
            if(matrix[i][0]==0) firstCol = 1;
        }

        for(int j=0; j<m; j++) {
            if(matrix[0][j]==0) firstRow = 1;
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(matrix[i][j]==0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(matrix[i][0]==0 || matrix[0][j]==0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstCol) {
            for(int i=0; i<n; i++) {
                matrix[i][0] = 0;
            }
        }

        if(firstRow) {
            for(int j=0; j<m; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};


// ================================================================================

// optimized
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        set<int> rows;
        set<int> cols;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j]==0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for(auto i : rows) {
            for(int j=0; j<m; j++) {
                matrix[i][j] = 0;
            }
        }

        for(auto j : cols) {
            for(int i=0; i<n; i++) {
                matrix[i][j] = 0;
            }
        }
        
    }
};
