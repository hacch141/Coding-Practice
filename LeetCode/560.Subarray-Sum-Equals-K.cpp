// 560. Subarray Sum Equals K

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0, prefix=0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++) {
            prefix += nums[i];
            if(prefix == k) {
                ans++;
            }
            if(mp.find(prefix-k) != mp.end()) {
                ans += mp[prefix-k];
            }
            mp[prefix]++;
        }
        return ans;
    }
};
