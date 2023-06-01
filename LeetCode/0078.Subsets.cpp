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

// =======================================================================

// BIT MANIPULATION

class Solution {

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int size = (1<<n);

        for(int i=0; i<size; i++) {
            vector<int> v;
            for(int j=0; j<32; j++) {
                if((i>>j) & 1) v.push_back(nums[j]);
            }
            ans.push_back(v);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// T : O(N*2^N)
// S : O(1)
