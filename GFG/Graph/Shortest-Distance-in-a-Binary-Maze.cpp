class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        // code here
        if(source == destination) return 0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{source.first,source.second}});
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        dist[source.first][source.second] = 0;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        while(!q.empty()) {
            int d = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]==1 && d+1<dist[nRow][nCol]) {
                    dist[nRow][nCol] = d+1;
                    if(nRow == destination.first && nCol == destination.second) {
                        return d+1;
                    } 
                    q.push({d+1,{nRow,nCol}});
                }
            }
        }
        return -1;
    }
};
