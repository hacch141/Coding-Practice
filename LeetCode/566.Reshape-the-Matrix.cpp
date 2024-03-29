// 566. Reshape the Matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat[0].size();
        if((mat.size()*mat[0].size()) != (r*c)) return mat;
        
        vector<vector<int>> ans(r,vector<int>(c));
        for(int i=0; i<(r*c); i++) {
            ans[i/c][i%c] = mat[i/n][i%n];
        }
        return ans;
    }
    
//     vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {  // 2nd method
//         if((mat.size()*mat[0].size()) != (r*c)) return mat;
//         int row = 0;
//         int col = 1;
//         vector<vector<int>> ans(r);
//         for(int i=0; i<mat.size(); i++) {
//             for(int j=0; j<mat[0].size(); j++) {
//                 ans[row].push_back(mat[i][j]);
//                 if(col<c) {
//                     col++;
//                 }
//                 else {
//                     row++;
//                     col = 1;
//                 }
//             }
//         }
//         return ans;
//     }
};
