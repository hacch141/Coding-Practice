// 3026. Maximum Good Subarray Sum

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> mp;
        int n = nums.size();
        long long sum = 0, ans = -1e15;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(mp.find(nums[i] - k) != mp.end()) {
                ans = max(ans, sum - mp[nums[i] - k]);
            }
            if(mp.find(nums[i] + k) != mp.end()) {
                ans = max(ans, sum - mp[nums[i] + k]);
            }
            if(mp.find(nums[i]) != mp.end()) mp[nums[i]] = min(mp[nums[i]], sum - nums[i]);
            else mp[nums[i]] = sum - nums[i];
        }
        
        return ans != -1e15 ? ans : 0;
    }
};
