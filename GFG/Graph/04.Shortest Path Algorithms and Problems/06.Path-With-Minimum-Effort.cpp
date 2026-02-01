// Path With Minimum Effort

class Solution {
    public int minimumEffortPath(int[][] heights) {
        int n = heights.length;
        int m = heights[0].length;

        int[][] diff = new int[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(diff[i], (int) 1e9);
        }

        diff[0][0] = 0;

        // PQ stores {effort, row, col}
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));

        pq.offer(new int[]{0, 0, 0});

        int[] delRow = {-1, 0, 1, 0};
        int[] delCol = {0, -1, 0, 1};

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int currDiff = cur[0];
            int r = cur[1];
            int c = cur[2];

            // Optional optimization
            if (currDiff > diff[r][c]) continue;

            for (int d = 0; d < 4; d++) {
                int nRow = r + delRow[d];
                int nCol = c + delCol[d];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) {

                    int newEffort = Math.max(
                            currDiff,
                            Math.abs(heights[r][c] - heights[nRow][nCol])
                    );

                    if (newEffort < diff[nRow][nCol]) {
                        diff[nRow][nCol] = newEffort;
                        pq.offer(new int[]{newEffort, nRow, nCol});
                    }
                }
            }
        }

        return diff[n - 1][m - 1];
    }
}

// ======================================================================

class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> diff(n, vector<int>(m,1e9));
        
        diff[0][0] = 0;
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,0}});
        
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int r = it.second.first;
            int c = it.second.second;
            int currdiff = it.first;
            for(int del=0; del<4; del++) {
                int nRow = r + delRow[del];
                int nCol = c + delCol[del];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m) {
                    if(max(currdiff,abs(heights[r][c] - heights[nRow][nCol])) < diff[nRow][nCol]) {
                        diff[nRow][nCol] = max(currdiff,abs(heights[r][c] - heights[nRow][nCol]));
                        pq.push({diff[nRow][nCol],{nRow,nCol}});
                    }
                }
            }
        }
        
        return diff[n-1][m-1];
    }
};

// T : O(N*M * Log(N*M))
// S : O(N*M)
