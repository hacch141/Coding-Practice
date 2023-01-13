// 78. Subsets

class Solution {

private:
    void helper(int idx, vector<int>& nums, vector<int>& ds,vector<vector<int>>& ans) {
        if(idx==nums.size()) {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        helper(idx+1,nums,ds,ans);
        ds.pop_back();
        helper(idx+1,nums,ds,ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0,nums,ds,ans);
        return ans;
    }
};
