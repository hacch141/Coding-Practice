// 2958. Length of Longest Subarray With at Most K Frequency

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, ans = 1;
        map<int,int> mp;
        for(int r = 0; r < n; r++) {
            mp[nums[r]]++;
            while(l < r && mp[nums[r]] > k) {
                mp[nums[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
