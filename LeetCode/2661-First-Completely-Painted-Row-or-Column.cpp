// 2661. First Completely Painted Row or Column

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        map<int,pair<int,int>> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }

        vector<int> row(n, 0), col(m, 0);
        for(int i = 0; i < n * m; i++) {
            auto [r, c] = mp[arr[i]];
            row[r]++;
            col[c]++;
            if(row[r] == m || col[c] == n) return i;
        }

        return 0;
    }
};
