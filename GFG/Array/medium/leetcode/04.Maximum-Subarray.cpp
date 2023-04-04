// 53. Maximum Subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;
        int maxSum = 0;
        int maxEle = INT_MIN;

        for(int i=0; i<n; i++) {

            sum += nums[i];
            maxSum = max(maxSum,sum);
            maxEle = max(maxEle,nums[i]);

            if(sum<0) {
                sum = 0;
            }

        }

        if(maxSum==0) return maxEle;

        return maxSum;
      
    }
};
