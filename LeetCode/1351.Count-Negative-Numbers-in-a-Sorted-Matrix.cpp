// 1351. Count Negative Numbers in a Sorted Matrix

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++) {
            int low = 0;
            int high = n-1;
            while(low<=high) {
                int mid = (high-low)/2 + low;
                if(grid[i][mid]<0) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            ans += n-low;
        }
        return ans;
    }
};
