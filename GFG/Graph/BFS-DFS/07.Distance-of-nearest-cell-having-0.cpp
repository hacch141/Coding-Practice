// Distance of nearest cell having 0

import java.util.*;

class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;

        int[][] ans = new int[n][m];
        Queue<int[]> q = new LinkedList<>();

        // Push all 0-cells into queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.offer(new int[]{i, j});
                }
            }
        }

        int[] delRow = {-1, 0, 1, 0};
        int[] delCol = {0, -1, 0, 1};

        int dis = 1;

        while (!q.isEmpty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int[] curr = q.poll();
                int row = curr[0];
                int col = curr[1];

                for (int d = 0; d < 4; d++) {
                    int nRow = row + delRow[d];
                    int nCol = col + delCol[d];

                    if (nRow >= 0 && nRow < n &&
                        nCol >= 0 && nCol < m &&
                        ans[nRow][nCol] == 0 &&
                        mat[nRow][nCol] == 1) {

                        ans[nRow][nCol] = dis;
                        q.offer(new int[]{nRow, nCol});
                    }
                }
            }
            dis++;
        }
        return ans;
    }
}

// ==================================================================

// BFS
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        vector<int> delRow = {-1,0,+1,0};
        vector<int> delCol = {0,-1,0,+1};

        int dis = 1;

        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int del=0; del<4; del++) {
                    int nRow = row + delRow[del];
                    int nCol = col + delCol[del];
                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && ans[nRow][nCol]==0 && mat[nRow][nCol]==1) {
                        ans[nRow][nCol] = dis;
                        q.push({nRow,nCol});
                    }
                }
            }
            dis++;
        }
        
        return ans;
    }
};

// T : O(N*M)
// S : O(N*M)
