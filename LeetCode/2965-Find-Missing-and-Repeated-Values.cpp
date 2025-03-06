// 2965. Find Missing and Repeated Values

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> vis((n * n) + 1, false);
        vector<int> ans(2);
        for(auto &row : grid) {
            for(auto &i : row) {
                if(vis[i]) ans[0] = i;
                vis[i] = true;
            }
        }
        for(int i = 1; i <= n * n; i++) {
            if(!vis[i]) ans[1] = i;
        }
        return ans;
    }
};

// =====================================================

//https://leetcode.com/problems/find-missing-and-repeated-values/editorial
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), n2 = n * n;
        long long normal_sum_diff = - (n2 * (n2 + 1LL)) / 2, square_sum_diff = -((n2) * (n2 + 1LL) * (2 * n2 + 1)) / 6;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                normal_sum_diff += grid[i][j];
                square_sum_diff += grid[i][j] * grid[i][j];
            }
        }
        vector<int> ans(2);
        ans[0] = (normal_sum_diff + (square_sum_diff/normal_sum_diff)) / 2;
        ans[1] = (- normal_sum_diff + (square_sum_diff/normal_sum_diff)) / 2;
        return ans;
    }
};
