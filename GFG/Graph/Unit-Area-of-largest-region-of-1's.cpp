class Solution {
    private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>& matrix, int delRow[], int delCol[], int n, int m) {
        vis[row][col] = 1;
        for(int i=0; i<4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && matrix[nRow][nCol]==1) {
                dfs(nRow, nCol, vis, matrix, delRow, delCol, n, m);
                
            }
        }
    }
    
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        vector<vector<int>> vis(N, vector<int> (M, 0));
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        for(int i=0; i<N; i++) {
            if(!vis[i][0] && matrix[i][0]==1) {
                dfs(i, 0, vis, matrix, delRow, delCol, N, M);
            }
            if(!vis[i][M-1] && matrix[i][M-1]==1) {
                dfs(i, M-1, vis, matrix, delRow, delCol, N, M);
            }
        }
        for(int j=0; j<M; j++) {
            if(!vis[0][j] && matrix[0][j]==1) {
                dfs(0, j, vis, matrix, delRow, delCol, N, M);
            }
            if(!vis[N-1][j] && matrix[N-1][j]) {
                dfs(N-1, j, vis, matrix, delRow, delCol, N, M);
            }
        }
        
        int ans = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(!vis[i][j] && matrix[i][j]==1) {
                    ans++;
                    dfs(i, j, vis, matrix, delRow, delCol, N, M);
                }
            }
        }
        return ans;
    }
};
