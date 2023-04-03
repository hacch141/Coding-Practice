class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dummy = matrix;
       
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j]==0) {
                    int temp = 0;
                    if(i-1>=0) {
                        temp += matrix[i-1][j];
                        dummy[i-1][j] = 0;
                    }
                    if(j-1>=0) {
                        temp += matrix[i][j-1];
                        dummy[i][j-1] = 0;
                    }
                    if(i+1<n) {
                        temp += matrix[i+1][j];
                        dummy[i+1][j] = 0;
                    }
                    if(j+1<m) {
                        temp += matrix[i][j+1];
                        dummy[i][j+1] = 0;
                    }
                    dummy[i][j] = temp;
                }
            }
        }
        matrix = dummy;
    }
};
