// 643. Maximum Average Subarray I

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        double window = 0;
        int n = nums.size();
        int fast = 0;
        int slow = 0;
        for(fast=0; fast<k; fast++) {
            window += nums[fast];
        }
        ans = max(ans,window/k);
        while(fast<n) {
            window += nums[fast++];
            window -= nums[slow++];
            ans = max(ans,window/k);
        }
        return ans;
    }
};
