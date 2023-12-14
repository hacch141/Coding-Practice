// 2482. Difference Between Ones and Zeros in Row and Column

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> onesRow(n,0), onesCol(m,0), zerosRow(n,0), zerosCol(m,0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    onesRow[i]++;
                    onesCol[j]++;
                }
                else {
                    zerosRow[i]++;
                    zerosCol[j]++;
                }
            }
        }

        vector<vector<int>> ans(n, vector<int>(m,0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }

        return ans;
    }
};



// ========================================================================================



class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> onesRow(n,0), onesCol(m,0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }

        vector<vector<int>> ans(n, vector<int>(m,0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans[i][j] = 2*(onesRow[i] + onesCol[j]) - m - n;
            }
        }

        return ans;
    }
};
