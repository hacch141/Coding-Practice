// 1368. Minimum Cost to Make at Least One Valid Path in a Grid

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
        cost[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});

        vector<int> dx = {0, 0, +1, -1};
        vector<int> dy = {+1, -1, 0, 0};

        while(!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int c1 = v[0], x1 = v[1], y1 = v[2];
            for(int k = 0; k < 4; k++) {
                int x2 = x1 + dx[k], y2 = y1 + dy[k];
                if(x2 >= 0 && x2 < n && y2 >= 0 && y2 < m) {
                    int c2 = cost[x1][y1] + (grid[x1][y1] != k + 1);
                    if(c2 < cost[x2][y2]) {
                        cost[x2][y2] = c2;
                        pq.push({c2, x2, y2});
                    }
                }
            }
        }

        return cost[n - 1][m - 1];
    }
};

// ================================================================================================

// Code with MIK
//Approach-1 (Backtracking DFS to try all paths) - TLE
//T.C : O(4^(m*n))
//S.C : O(m*n)
class Solution {
public:
    vector<vector<int>> dir={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int cost) {
        if(i == m-1 && j == n-1) { //reached destination
            return cost;
        }

        visited[i][j] = true;

        //explore
        int minCost = INT_MAX;
        for(int dir_i = 0; dir_i <= 3; dir_i++) {
            int i_ = i + dir[dir_i][0];
            int j_ = j + dir[dir_i][1];

            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                int nextCost = cost + ((grid[i][j]-1 != dir_i) ? 1 : 0);
                
                minCost = min(minCost, dfs(i_, j_, grid, visited, nextCost));
            }
        }

        visited[i][j] = false;
        return minCost;
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return dfs(0, 0, grid, visited, 0);//explore all paths by backtracking
    }
};


//Approach-2 (Dijkstra's Algorithm) - Accepted
//T.C : O((m*n) * log(m*n))
//S.C : O(m*n)
class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; //min-heap of int
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        pq.push({0, 0, 0});
        result[0][0] = 0;
        //T.C : O(m*n * log(m*n))
        //S.C : O(m*n)
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop(); //log(size of pq)

            int currCost = curr[0];
            int i = curr[1];
            int j = curr[2];

            if(result[i][j] < currCost) {
                continue;
            }

            for(int dir_i = 0; dir_i <= 3; dir_i++) {
                int i_ = i + dir[dir_i][0];
                int j_ = j + dir[dir_i][1];

                if(i_ >= 0 && j_ >= 0 && i_ < m && j_ < n) {
                    int gridDir = grid[i][j];
                    int dirCost = ((gridDir-1 != dir_i) ? 1 : 0);

                    int newCost = currCost + dirCost;

                    if(newCost < result[i_][j_]) {
                        result[i_][j_] = newCost;
                        pq.push({newCost, i_, j_});
                    }
                }
            }
        }
        return result[m-1][n-1]; //min cost to reach (m-1, n-1)
    }
};
