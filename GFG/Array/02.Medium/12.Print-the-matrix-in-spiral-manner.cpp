// Print the matrix in spiral manner

class Solution {
    public List<Integer> spiralMatrix(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        int topRow = 0, leftCol = 0;
        int bottomRow = n - 1, rightCol = m - 1;

        List<Integer> ans = new ArrayList<>();
        while (topRow <= bottomRow && leftCol <= rightCol) {

            // top row
            for (int i = leftCol; i <= rightCol; i++) {
                ans.add(matrix[topRow][i]);
            }
            topRow++;

            // right column
            for (int i = topRow; i <= bottomRow; i++) {
                ans.add(matrix[i][rightCol]);
            }
            rightCol--;

            // bottom row
            if (topRow <= bottomRow) {
                for (int i = rightCol; i >= leftCol; i--) {
                    ans.add(matrix[bottomRow][i]);
                }
                bottomRow--;
            }

            // left column
            if (leftCol <= rightCol) {
                for (int i = bottomRow; i >= topRow; i--) {
                    ans.add(matrix[i][leftCol]);
                }
                leftCol++;
            }
        }

        return ans;
    }
}

// ==============================================================================================

vector<int> spiralMatrix(vector<vector<int>>&MATRIX) {
    // Write your code here.
    int n = MATRIX.size();
    int m = MATRIX[0].size();

    int topRow=0, leftCol=0;
    int bottomRow=n-1, rightCol=m-1;

    vector<int> ans;
    while(topRow<=bottomRow && leftCol<=rightCol) {

        for(int i=leftCol; i<=rightCol; i++) {
            ans.push_back(MATRIX[topRow][i]);
        }
        topRow++;

        for(int i=topRow; i<=bottomRow; i++) {
            ans.push_back(MATRIX[i][rightCol]);
        }
        rightCol--;

        if(topRow<=bottomRow) {
            for(int i=rightCol; i>=leftCol; i--) {
                ans.push_back(MATRIX[bottomRow][i]);
            }
        }
        bottomRow--;

        if(leftCol<=rightCol) {
            for(int i=bottomRow; i>=topRow; i--) {
                ans.push_back(MATRIX[i][leftCol]);
            }
        }
        leftCol++;
        
    }

    return ans;
}
// T : O(M*N)
// S : O(1)
