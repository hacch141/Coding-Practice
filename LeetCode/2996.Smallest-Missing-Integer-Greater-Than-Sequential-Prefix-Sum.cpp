// 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i : nums) mp[i]++;

        int prefix = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == 1 + nums[i-1]) prefix += nums[i];
            else break;
        }

        while(mp.find(prefix) != mp.end()) prefix++;

        return prefix;
    }
};
