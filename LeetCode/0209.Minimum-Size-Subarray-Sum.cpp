// 209. Minimum Size Subarray Sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;

        while(right < nums.size()) {
            sum += nums[right++];
            while(left <= right && sum >= target) {
                ans = min(ans,right - left);
                sum -= nums[left++];
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
