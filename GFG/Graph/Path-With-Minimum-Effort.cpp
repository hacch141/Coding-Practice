class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        priority_queue< pair<int,pair<int,int>>, vector< pair<int,pair<int,int>> >, greater< pair<int,pair<int,int>> > > pq;
        pq.push({0,{0,0}});
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int> (m,1e9));
        dist[0][0] = 0;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        while(!pq.empty()) {
            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1) return d;
            for(int i=0; i<4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m) {
                    int newdist = max(d , abs(heights[row][col]-heights[nRow][nCol]));
                    if(newdist < dist[nRow][nCol]) {
                        dist[nRow][nCol] = newdist;
                        pq.push({newdist,{nRow,nCol}});
                    }
                }
            }
        }
        return 0;
    }
};
