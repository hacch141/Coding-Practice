// 1254. Number of Closed Islands

// DFS
class Solution {

public:

    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int delRow[], int delCol[], int& n, int& m) {
        
        vis[row][col] = 1;
        
        for(int i=0; i<4; i++) {
            
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]==0) {
                dfs(nRow,nCol,vis,grid,delRow,delCol,n,m);
            }
            
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));

        int delRow[4] = {-1,0,+1,0};
        int delCol[4] = {0,-1,0,+1};

        for(int i=0; i<n; i++) {
            if(grid[i][0]==0 && !vis[i][0]) {
                dfs(i,0,vis,grid,delRow,delCol,n,m);
            }
            if(grid[i][m-1]==0 && !vis[i][m-1]) {
                dfs(i,m-1,vis,grid,delRow,delCol,n,m);
            }
        }

        for(int j=0; j<m; j++) {
            if(grid[0][j]==0 && !vis[0][j]) {
                dfs(0,j,vis,grid,delRow,delCol,n,m);
            }
            if(grid[n-1][j]==0 && !vis[n-1][j]) {
                dfs(n-1,j,vis,grid,delRow,delCol,n,m);
            }
        }

        int ans = 0;
        for(int i=1; i<n-1; i++) {
            for(int j=0; j<m-1; j++) {
                if(grid[i][j]==0 && !vis[i][j]) {
                    ans++;
                    dfs(i,j,vis,grid,delRow,delCol,n,m);
                }
            }
        }

        return ans;
    }
};


// =====================================================================================

// BFS

class Solution {

public:

    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int delRow[], int delCol[], int& n, int& m) {

        vis[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty()) {
            
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {

                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]==0) {
                    vis[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                }
                
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));

        int delRow[4] = {-1,0,+1,0};
        int delCol[4] = {0,-1,0,+1};

        for(int i=0; i<n; i++) {
            if(grid[i][0]==0 && !vis[i][0]) {
                bfs(i,0,vis,grid,delRow,delCol,n,m);
            }
            if(grid[i][m-1]==0 && !vis[i][m-1]) {
                bfs(i,m-1,vis,grid,delRow,delCol,n,m);
            }
        }

        for(int j=0; j<m; j++) {
            if(grid[0][j]==0 && !vis[0][j]) {
                bfs(0,j,vis,grid,delRow,delCol,n,m);
            }
            if(grid[n-1][j]==0 && !vis[n-1][j]) {
                bfs(n-1,j,vis,grid,delRow,delCol,n,m);
            }
        }

        int ans = 0;
        for(int i=1; i<n-1; i++) {
            for(int j=0; j<m-1; j++) {
                if(grid[i][j]==0 && !vis[i][j]) {
                    ans++;
                    bfs(i,j,vis,grid,delRow,delCol,n,m);
                }
            }
        }

        return ans;
    }
};
