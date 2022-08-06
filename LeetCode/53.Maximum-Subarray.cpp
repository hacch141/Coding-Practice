// 53. Maximum Subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            maxSum = max(maxSum,sum);
            if(sum<0) {
                sum = 0;
            }
        }
        return maxSum;
    }
    
//     int maxSubArray(vector<int>& nums) { //2nd Method
//         int ans = nums[0];
//         int currMax = nums[0];
        
//         for(int i=1; i<nums.size(); i++) {
//             currMax = max(currMax+nums[i],nums[i]);
//             ans = max(ans,currMax);
//         }
//         return ans;
//     }
};
