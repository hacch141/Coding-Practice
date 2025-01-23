// 1267. Count Servers that Communicate

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<int> fr(n, 0), fc(m, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    fr[i]++;
                    fc[j]++;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] && (fr[i] > 1 || fc[j] > 1)) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
