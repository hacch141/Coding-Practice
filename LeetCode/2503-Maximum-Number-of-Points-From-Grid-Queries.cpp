// 2503. Maximum Number of Points From Grid Queries

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int len = queries.size(), n = grid.size(), m = grid[0].size();
        vector<vector<int>> v;
        for(int i = 0; i < len; i++) {
            v.push_back({queries[i], i});
        }

        sort(v.begin(), v.end());

        int cnt = 0;
        vector<int> ans(len, 0);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vis[0][0] = true;

        vector<int> dx = {0, +1, 0, -1};
        vector<int> dy = {+1, 0, -1, 0};

        for(int i = 0; i < len; i++) {
            while(!pq.empty() && pq.top()[0] < v[i][0]) {
                auto it = pq.top();
                pq.pop();
                cnt++;

                int x = it[1], y = it[2];
                for(int j = 0; j < 4; j++) {
                    int nx = x + dx[j], ny = y + dy[j];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                        vis[nx][ny] = true;
                        pq.push({grid[nx][ny], nx, ny});
                    }
                }
            }

            ans[v[i][1]] = cnt;
        }

        return ans;
    }
};
