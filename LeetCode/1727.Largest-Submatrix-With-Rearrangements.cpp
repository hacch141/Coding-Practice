// 1727. Largest Submatrix With Rearrangements

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 1) matrix[i][j] += matrix[i-1][j];
            }
        }

        int ans = INT_MIN;
        for(int i=0; i<n; i++) {
            sort(matrix[i].begin(),matrix[i].end());
            for(int j=0; j<m; j++) {
                int curr = (m-j)*matrix[i][j];
                ans = max(ans,curr);
            }
        }

        return ans;
    }
};
