// 1926. Nearest Exit from Entrance in Maze

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();

        vector<int> dx = {-1, 0, +1, 0};
        vector<int> dy = {0, -1, 0, +1};

        int cnt = 0;
        set<pair<int,int>> vis;

        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        vis.insert({entrance[0], entrance[1]});

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto it = q.front();   
                q.pop();
                int x = it.first, y = it.second;
                if(cnt > 0 && (x ==0 || x == n - 1 || y == 0 || y == m - 1)) return cnt;
                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == '.' && !vis.count({nx, ny})) {
                        q.push({nx, ny});
                        vis.insert({nx, ny});
                    }
                }
            }
            cnt++;
        }

        return -1;
    }
};
