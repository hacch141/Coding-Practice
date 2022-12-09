class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int topRow = 0;
        int leftCol = 0;
        int bottomRow = matrix.size()-1;
        int rightCol = matrix[0].size()-1;
        vector<int> ans;
        while(topRow <= bottomRow && leftCol <= rightCol) {
            for(int i=leftCol; i<=rightCol; i++) {
                ans.push_back(matrix[topRow][i]);
            }
            topRow++;
            for(int i=topRow; i<=bottomRow; i++) {
                ans.push_back(matrix[i][rightCol]);
            }
            rightCol--;
            if(topRow <= bottomRow) {
                for(int i=rightCol; i>=leftCol; i--) {
                    ans.push_back(matrix[bottomRow][i]);
                }
                bottomRow--;
            }
            if(leftCol <= rightCol) {
                for(int i=bottomRow; i>=topRow; i--) {
                    ans.push_back(matrix[i][leftCol]);
                }
                leftCol++;
            }
        }
        return ans;
    }
};
