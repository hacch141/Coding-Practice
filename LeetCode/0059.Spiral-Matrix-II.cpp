// 59. Spiral Matrix II

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n,0));
        int top = 0, left = 0, right = n-1, bottom = n-1;
        int cnt = 0;
        while(top<=bottom && left<=right) {

            for(int i=left; i<=right; i++) {
                ans[top][i] = ++cnt;
            }
            top++;

            for(int i=top; i<=bottom; i++) {
                ans[i][right] = ++cnt;
            }
            right--;

            if(top<=bottom) {
                for(int i=right; i>=left; i--) {
                    ans[bottom][i] = ++cnt;
                }
            }
            bottom--;

            if(left<=right) {
                for(int i=bottom; i>=top; i--) {
                    ans[i][left] = ++cnt;
                }
            }
            left++;

        }
        return ans;
    }
};
