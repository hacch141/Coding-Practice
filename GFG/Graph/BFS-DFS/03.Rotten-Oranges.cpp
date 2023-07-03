// Rotten Oranges

// BFS
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        
        int fresh = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    vis[i][j] = 1;
                    q.push({i,j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};
        
        int time = 0;
        int rotten = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                for(int del=0; del<4; del++) {
                    int nRow = r + delRow[del];
                    int nCol = c + delCol[del];
                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]==1) {
                        rotten++;
                        vis[nRow][nCol] = 1;
                        q.push({nRow,nCol});
                    }
                }
                
            }
            time++;
        }
        
        if(fresh != rotten) return -1;
        return time-1;
    }
};

// T : O(N*M)
// S : O(N*M)
