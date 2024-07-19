// 1380. Lucky Numbers in a Matrix

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> rowMIN, colMAX;
        for(int i = 0; i < n; i++) {
            int mn = INT_MAX;
            for(int j = 0; j < m; j++) {
                mn = min(mn, matrix[i][j]);
            }
            rowMIN.push_back(mn);
        }
        for(int j = 0; j < m; j++) {
            int mx = INT_MIN;
            for(int i = 0; i < n; i++) {
                mx = max(mx, matrix[i][j]);
            }
            colMAX.push_back(mx);
        }

        vector<int> ans;
        for(auto i : rowMIN) {
            for(auto j : colMAX) {
                if(i == j) ans.push_back(i);
            }
        }
        return ans;
    }
};
