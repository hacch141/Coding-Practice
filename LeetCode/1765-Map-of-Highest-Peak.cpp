// 1765. Map of Highest Peak

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));

        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> dx = {+1, 0, -1, 0};
        vector<int> dy = {0, +1, 0, -1};

        int height = 1;
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                auto it = q.front();
                q.pop();
                int x = it.first, y = it.second;
                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && ans[nx][ny] == -1) {
                        ans[nx][ny] = height;
                        q.push({nx, ny});
                    }
                }
            }
            height++;
        }

        return ans;
    }
};
