// 1074. Number of Submatrices That Sum to Target

class Solution {
public:

    vector<vector<int>> prefix;

    void genPrefix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prefix = matrix;
        for(int i=0; i<n; i++) {
            for(int j=1; j<m; j++) {
                prefix[i][j] = prefix[i][j-1] + matrix[i][j];
            }
        }

        for(int j=0; j<m; j++) {
            for(int i=1; i<n; i++) {
                prefix[i][j] = prefix[i][j] + prefix[i-1][j];
            }
        }

    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = prefix[row2][col2];
        if(row1-1 >= 0) ans -= prefix[row1-1][col2];
        if(col1-1 >= 0) ans -= prefix[row2][col1-1];
        if(row1-1 >= 0 && col1-1 >= 0) ans += prefix[row1-1][col1-1];
        return ans;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        genPrefix(matrix);

        unordered_map<int,int> mp;
        int ans = 0;
        for(int colSt = 0; colSt < m; colSt++) {
            for(int colEnd = colSt; colEnd < m; colEnd++) {
                mp.clear();
                mp[0] = 1;
                for(int row = 0; row < n; row++) {
                    int area = sumRegion(0, colSt, row, colEnd);
                    ans += mp[area - target];
                    mp[area]++;
                }
            }
        }

        return ans;
    }
};
