// 1. Two Sum

class Solution {
public:
  
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        unordered_map<int, int> mp;
        int n = nums.size();
      
        for(int i=0; i<n; i++) {
            if(mpmp.count(target - nums[i])) {
                ans[0] = mp[target - nums[i]];
                ans[1] = i;
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};
