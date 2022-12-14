class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<pair<int,int>,int>> q;
        int fresh_org = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else if(grid[i][j] == 1) {
                    fresh_org++;
                }
            }
        }
        int tm = 0;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        int cnt = 0;
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            for(int i=0; i<4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && vis[nRow][nCol]==0 && grid[nRow][nCol]==1) {
                    q.push({{nRow,nCol},t+1});
                    vis[nRow][nCol] = 2;
                    cnt++;
                }
            }
        }
        if(cnt != fresh_org) return -1;
        return tm;
    }
};
