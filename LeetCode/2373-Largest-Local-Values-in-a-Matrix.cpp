// 2373. Largest Local Values in a Matrix

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> temp = grid;

        int dx[8] = {-1, 0, +1, 0, +1, -1, +1, -1};
        int dy[8] = {0, -1, 0, +1, +1, -1, -1, +1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        temp[nx][ny] = max(temp[nx][ny], grid[i][j]);
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for(int i = 1; i < n - 1; i++) {
            vector<int> v;
            for(int j = 1; j < n - 1; j++) {
                v.push_back(temp[i][j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
