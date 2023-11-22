// 1424. Diagonal Traverse II

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;

        int row = nums.size();
        int col = 0;

        for(auto v : nums) {
            col = max(col , (int)v.size());
        }
 
        vector<vector<int>> mp(row+col);

        for(int r=row-1; r>=0; r--) {
            for(int c=0; c<nums[r].size(); c++) {
                mp[r+c].push_back(nums[r][c]);
            }
        }

        for(auto v : mp) {
            ans.insert(ans.end(),v.begin(),v.end());
        }

        return ans;
    }
};
