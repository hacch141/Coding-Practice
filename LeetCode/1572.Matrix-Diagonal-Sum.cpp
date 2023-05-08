// 1572. Matrix Diagonal Sum

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += mat[i][i];
            ans += mat[i][n-1-i];
            if(i == n-1-i) ans -= mat[i][i];
        }
        return ans;
    }
};
