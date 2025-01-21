// 2017. Grid Game

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        long long r0_total = 0, r1_total = 0;
        for(int i = 0; i < n; i++) {
            r0_total += grid[0][i];
            r1_total += grid[1][i];
        }

        long long r0_curr = 0, r1_curr = 0, ans = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            r0_curr += grid[0][i];
            ans = min(ans, max(r0_total - r0_curr, r1_curr));
            r1_curr += grid[1][i];
        }

        return ans;
    }
};
