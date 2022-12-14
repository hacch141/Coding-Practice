// Flood fill Algorithm

class Solution {
    
private:
    void dfs(int row, int col, int initial_col, int newColor, vector<vector<int>> &ans, vector<vector<int>> image, int delRow[], int delCol[]) {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i=0; i<4; i++) {
            int nRow = row+delRow[i];
            int nCol = col+delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol]==initial_col && ans[nRow][nCol]!=newColor) {
                dfs(nRow, nCol, initial_col, newColor, ans, image, delRow, delCol);
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int initial_col = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(sr, sc, initial_col, newColor, ans, image, delRow, delCol);
        return ans;
    }
};
