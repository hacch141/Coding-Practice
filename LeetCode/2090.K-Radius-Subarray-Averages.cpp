// 2090. K Radius Subarray Averages

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        if(k==0) return nums;
        if((2*k)+1 > n) return ans;
        long long window = 0;
        int fast = 0;
        int slow = 0;
        int len = (2*k)+1;
        for(fast=0; fast<len; fast++) {
            window += nums[fast];
        }
        ans[slow+k] = window/len;
        while(fast<n) {
            window += nums[fast++];
            window -= nums[slow++];
            ans[slow+k] = window/len;
        }
        return ans;
    }
};
