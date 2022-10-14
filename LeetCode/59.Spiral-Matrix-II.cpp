// 59. Spiral Matrix II

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int topRow = 0;
        int leftCol = 0;
        int bottomRow = n-1;
        int rightCol = n-1;
        int val = 1;
        vector<vector<int>> matrix(n,vector<int>(n));
        
        while(topRow <= bottomRow && leftCol <= rightCol) {
            for(int i=leftCol; i<=rightCol; i++) {
                matrix[topRow][i] = val++;
            }
            topRow++;

            for(int i=topRow; i<=bottomRow; i++) {
                matrix[i][rightCol] = val++;
            }
            rightCol--;
            
            for(int i=rightCol; i>=leftCol; i--) {
                matrix[bottomRow][i] = val++;
            }
            bottomRow--;
            
            for(int i=bottomRow; i>=topRow; i--) {
                matrix[i][leftCol] = val++;
            }
            leftCol++;
        }
        return matrix;
    }
};
