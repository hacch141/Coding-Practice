// 1162. As Far from Land as Possible

class Solution {

public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int cnt = 0;
        vector<vector<int>> dp(n, vector<int> (m,0));
        queue<pair<int,int>> q;        
        int delRow[4] = {-1,0,+1,0};
        int delCol[4] = {0,+1,0,-1};

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1) {
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()) {
            int ele = q.size();
            cnt++;
            for(int i=0; i<ele; i++) {
                auto p = q.front();
                q.pop();
                int row = p.first;
                int col = p.second;
                for(int idx=0; idx<4; idx++) {
                    int nRow = row+delRow[idx];
                    int nCol = col+delCol[idx];
                    if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && !dp[nRow][nCol] && grid[nRow][nCol]==0) {
                        q.push({nRow,nCol});
                        dp[nRow][nCol] = cnt;
                        ans = max(ans,cnt);
                    }
                }
            }
        }
        if(ans == 0) return -1;
        return ans;
    }
};
