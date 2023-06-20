// 209. Minimum Size Subarray Sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int len = 0;
        int currSum = 0;
        int slow=0, fast=0;
        int n = nums.size();
        while(fast<n) {
            while(fast<n && currSum<target) {
                currSum += nums[fast++];
            }
            while(slow<=fast && currSum>=target) {
                ans = min(ans,fast-slow);
                currSum -= nums[slow++];
            }
        }
        return ans==INT_MAX ? 0 : ans;
    }
};
