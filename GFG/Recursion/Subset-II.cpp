class Solution {
    
  private:
    void helper(int idx, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
        ans.push_back(ds);
        for(int i=idx; i<nums.size(); i++) {
            if(i!=idx && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            helper(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }

  public:
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        helper(0,nums,ds,ans);
        return ans;
    }
};
