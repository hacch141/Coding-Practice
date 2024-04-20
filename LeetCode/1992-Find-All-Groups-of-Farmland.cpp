// 1992. Find All Groups of Farmland

class Solution {
public:

    void help(int i, int j, vector<vector<int>>& land, vector<int>& v) {
        if(i >= land.size() || j >= land[0].size() || land[i][j] != 1) return;
        land[i][j] = 2;
        v[2] = max(v[2], i);
        v[3] = max(v[3], j);
        help(i + 1, j, land, v);
        help(i, j + 1, land, v);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(land[i][j] == 1) {
                    vector<int> v = {i, j, -1, -1};
                    help(i, j, land, v);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};
