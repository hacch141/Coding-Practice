// 3394. Check if Grid can be Cut into Sections

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> row, col;
        for(auto &it : rectangles) {
            row.push_back({it[0], it[2]});
            col.push_back({it[1], it[3]});
        }
        
        sort(row.begin(), row.end());
        sort(col.begin(), col.end());

        int cnt_row = 0, cnt_col = 0, row_end = row[0][1], col_end = col[0][1];
        for(int i = 1; i < row.size(); i++) {
            cnt_row += row[i][0] >= row_end && row[i][0] != row[i - 1][0];
            cnt_col += col[i][0] >= col_end && col[i][0] != col[i - 1][0];
            row_end = max(row_end, row[i][1]);
            col_end = max(col_end, col[i][1]);
            if(cnt_row > 1 || cnt_col > 1) return true;
        }

        return false;
    }
};
