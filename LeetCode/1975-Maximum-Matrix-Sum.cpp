// 1975. Maximum Matrix Sum

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int cnt = 0, mn = INT_MAX;
        int n = matrix.size(), m = matrix[0].size();
        bool has_zero = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                sum += abs(matrix[i][j]);
                mn = min(mn, abs(matrix[i][j]));
                if(matrix[i][j] < 0) {
                    cnt++;
                }
                else if(matrix[i][j] == 0) {
                    has_zero = true;
                }
            }
        }
        if(!has_zero && (cnt & 1)) {
            sum -= 2 * mn;
        }
        return sum;
    }
};
