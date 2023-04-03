class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int n = nums.size();

        int prefix = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            prefix += nums[i];
            if(mp.find(prefix-k) != mp.end()) {
                ans += mp[prefix-k];
            }
            mp[prefix]++;
        }
        
        return ans;
    }
};
