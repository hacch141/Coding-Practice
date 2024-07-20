// 1605. Find Valid Matrix Given Row and Column Sums

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size(), r = 0, c = 0;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        while(r < n && c < m) {
            if(rowSum[r] == 0) {
                r++;
            }
            else if(colSum[c] == 0){
                c++;
            }
            else {
                int mn = min(rowSum[r], colSum[c]);
                grid[r][c] = mn;
                rowSum[r] -= mn;
                colSum[c] -= mn;
            }
        }
        return grid;
    }
};
