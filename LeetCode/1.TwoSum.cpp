// 1. Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> ans;
        unordered_map<int, int> map;
        
        for(int i=0; i<nums.size(); i++) {
            if(map.find(target-nums[i]) != map.end()) {
                ans.push_back(i);
                ans.push_back(map[target-nums[i]]);
                return ans;
            }
            map[nums[i]] = i;
        }
        return ans;
    }
};