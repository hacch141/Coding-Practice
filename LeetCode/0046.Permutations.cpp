// 46. Permutations

class Solution {

private:
    void helper(vector<int>& mpp, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
        if(ds.size()==nums.size()) {
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(!mpp[i]) {
                mpp[i] = 1;
                ds.push_back(nums[i]);
                helper(mpp,nums,ds,ans);
                mpp[i] = 0;
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        vector<int> mpp(n,0);
        helper(mpp,nums,ds,ans);
        return ans;
    }
};


// ==========================================================


class Solution {

private:
    void helper(int idx, vector<int>& nums, vector<vector<int>>& ans) {
        if(idx==nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++) {
            swap(nums[i],nums[idx]);
            helper(idx+1,nums,ans);
            swap(nums[i],nums[idx]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0,nums,ans);
        return ans;
    }
};
