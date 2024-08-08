// 885. Spiral Matrix III
class Solution {
public:

    bool ok(int x, int y, int rows, int cols) {
        return (x >= 0 && x < rows) && (y >= 0 && y < cols);
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int st = 1, x = rStart, y = cStart, steps = 1;
        ans.push_back({x, y});
        st++;
        while(st <= rows * cols) {
            for(int i = 0; i < steps; i++) {
                y++;
                if(ok(x, y, rows, cols)) {
                    ans.push_back({x, y});
                    st++;
                }
            }
            for(int i = 0; i < steps; i++) {
                x++;
                if(ok(x, y, rows, cols)) {
                    ans.push_back({x, y});
                    st++;
                }
            }
            steps++;
            for(int i = 0; i < steps; i++) {
                y--;
                if(ok(x, y, rows, cols)) {
                    ans.push_back({x, y});
                    st++;
                }
            }
            for(int i = 0; i < steps; i++) {
                x--;
                if(ok(x, y, rows, cols)) {
                    ans.push_back({x, y});
                    st++;
                }
            }
            steps++;
        }
        return ans;
    }
};
