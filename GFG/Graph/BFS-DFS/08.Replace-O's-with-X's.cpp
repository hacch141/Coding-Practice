// Replace O's with X's

class Solution{
    
private:
    void bfs(int row, int col, vector<vector<char>>& mat, vector<vector<int>>& vis, int& n, int& m) {
        vis[row][col] = 1;
        
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};
        
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int del=0; del<4; del++) {
                int nRow = r + delRow[del];
                int nCol = c + delCol[del];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && mat[nRow][nCol]=='O' && !vis[nRow][nCol]) {
                    vis[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                }
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>> ans = mat;
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        for(int i=0; i<n; i++) {
            if(mat[i][0]=='O' && !vis[i][0]) {
                bfs(i,0,mat,vis,n,m);
            }
            if(mat[i][m-1]=='O' && !vis[i][m-1]) {
                bfs(i,m-1,mat,vis,n,m);
            }
        }
        
        for(int j=0; j<m; j++) {
            if(mat[0][j]=='O' && !vis[0][j]) {
                bfs(0,j,mat,vis,n,m);
            }
            if(mat[n-1][j]=='O' && !vis[n-1][j]) {
                bfs(n-1,j,mat,vis,n,m);
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && mat[i][j]=='O') {
                    ans[i][j] = 'X';
                }
            }
        }
        
        return ans;
    }
};

// T : O(N*M)
// S : O(N*M)
