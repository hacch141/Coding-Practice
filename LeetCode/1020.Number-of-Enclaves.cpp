// 1020. Number of Enclaves


// DFS
class Solution {

public:

    void dfs(int row, int col, vector<vector<int>>& vis, int delRow[], int delCol[], int& n, int& m) {
        vis[row][col] = 1;

        for(int i=0; i<4; i++) {

            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol]) {
                dfs(nRow,nCol,vis,delRow,delCol,n,m);
            }

        }
    }


    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==0) {
                    vis[i][j] = 1;
                }
            }
        }

        int delRow[4] = {-1,0,+1,0};
        int delCol[4] = {0,-1,0,+1};

        for(int i=0; i<n; i++) {
            if(!vis[i][0]) {
                dfs(i,0,vis,delRow,delCol,n,m);
            }
            if(!vis[i][m-1]) {
                dfs(i,m-1,vis,delRow,delCol,n,m);
            }
        }

        for(int j=0; j<m; j++) {
            if(!vis[0][j]) {
                dfs(0,j,vis,delRow,delCol,n,m);
            }
            if(!vis[n-1][j]) {
                dfs(n-1,j,vis,delRow,delCol,n,m);
            }
        }

        int ans = 0;
        for(int i=1; i<n-1; i++) {
            for(int j=1; j<m-1; j++) {
                if(!vis[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};


// BFS
class Solution {

public:

    void bfs(int row, int col, vector<vector<int>>& vis, int delRow[], int delCol[], int& n, int& m) {
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

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol]) {
                    vis[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                }

            }
        }
    }


    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==0) {
                    vis[i][j] = 1;
                }
            }
        }

        int delRow[4] = {-1,0,+1,0};
        int delCol[4] = {0,-1,0,+1};

        for(int i=0; i<n; i++) {
            if(!vis[i][0]) {
                bfs(i,0,vis,delRow,delCol,n,m);
            }
            if(!vis[i][m-1]) {
                bfs(i,m-1,vis,delRow,delCol,n,m);
            }
        }

        for(int j=0; j<m; j++) {
            if(!vis[0][j]) {
                bfs(0,j,vis,delRow,delCol,n,m);
            }
            if(!vis[n-1][j]) {
                bfs(n-1,j,vis,delRow,delCol,n,m);
            }
        }

        int ans = 0;
        for(int i=1; i<n-1; i++) {
            for(int j=1; j<m-1; j++) {
                if(!vis[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
