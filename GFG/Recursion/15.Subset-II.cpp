// Subset II

class Solution {

  public:
  
    void solve(int idx, int& n, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
        ans.push_back(ds);
        for(int i=idx; i<n; i++) {
            if(i>idx && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            solve(i+1,n,nums,ds,ans);
            ds.pop_back();
        }
    }
  
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        solve(0,n,nums,ds,ans);
        return ans;
    }
};

// T : O(K*2^N)
// S : O(K*2^N)
