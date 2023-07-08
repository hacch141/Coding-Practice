// Shortest path in a binary maze

// Using Djikstra's Algo
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        // code here
        if (source.first == destination.first && source.second == destination.second) return 0;

        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        dist[source.first][source.second] = 0;
        queue< pair<int,pair<int,int>> > q;
        q.push({0,source});
        
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};
        
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                auto it = q.front();
                int r = it.second.first;
                int c = it.second.second;
                q.pop();
                if(r == destination.first && c == destination.second) {
                    return dist[r][c];
                }
                for(int del=0; del<4; del++) {
                    int nRow = r + delRow[del];
                    int nCol = c + delCol[del];
                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]==1) {
                        if(1 + dist[r][c] < dist[nRow][nCol]) {
                            dist[nRow][nCol] = 1 + dist[r][c];
                            q.push({dist[nRow][nCol],{nRow,nCol}});
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};

// T : O(M*N)
// S : O(M*N)


// Normal BFS
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push(source);
        
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};
        
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if(r == destination.first && c == destination.second) {
                    return dist[r][c];
                }
                for(int del=0; del<4; del++) {
                    int nRow = r + delRow[del];
                    int nCol = c + delCol[del];
                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && dist[nRow][nCol]==0 && grid[nRow][nCol]==1) {
                        dist[nRow][nCol] = 1 + dist[r][c];
                        q.push({nRow,nCol});
                    }
                }
            }
        }
        
        return -1;
    }
};

// T : O(N*M)
// S : O(N*M)
