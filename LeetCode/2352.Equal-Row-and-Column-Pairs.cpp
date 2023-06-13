// 2352. Equal Row and Column Pairs


class Solution {
public:

    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>,int> mp;
        for(int i=0; i<n; i++) {
            mp[grid[i]]++;
        }

        int ans = 0;
        for(int j=0; j<n; j++) {
            vector<int> col;
            for(int i=0; i<n; i++) {
                col.push_back(grid[i][j]);
            }
            ans += mp[col];
        }
        return ans;
    }
};



class Solution {
public:

    bool isValid(int i, int j, int n, vector<vector<int>>& grid) {
        for(int idx=0; idx<n; idx++) {
            if(grid[i][idx] != grid[idx][j]) return false;
        }
        return true;
    }

    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rowSum(n,0);
        vector<int> colSum(n,0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                colSum[j] += grid[i][j];
                rowSum[i] += grid[i][j];
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(rowSum[i]==colSum[j]) {
                    if(isValid(i,j,n,grid)) ans++;
                }
            }
        }
        return ans;
    }
};
