// 542. 01 Matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m,0));
        vector<vector<int>> vis(n, vector<int>(m,0));

        queue<pair<int,int>> q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]==0) {
                    q.push({i,j});
                }
            }
        }

        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};

        int d = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int del=0; del<4; del++) {
                    int nRow = r + delRow[del];
                    int nCol = c + delCol[del];
                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && mat[nRow][nCol]==1) {
                        ans[nRow][nCol] = d;
                        vis[nRow][nCol] = 1;
                        q.push({nRow,nCol});
                    }
                }
            }
            d++;
        }
        return ans;
    }
};
