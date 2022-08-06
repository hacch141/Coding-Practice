// 918. Maximum Sum Circular Subarray

class Solution {
public:
    
    int kedanes(vector<int>& nums) {
        int ans = nums[0];
        int maxEnd = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            maxEnd = max(maxEnd+nums[i],nums[i]);
            ans = max(ans,maxEnd);
        }
        return ans;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_normal = kedanes(nums);
        if(max_normal<0) {
            return max_normal;
        }
        
        int nums_sum = 0;
        for(int i=0; i<nums.size(); i++) {
            nums_sum += nums[i];
            nums[i] = -nums[i];
        }
        
        int max_circular = nums_sum + kedanes(nums);
        return max(max_normal,max_circular);
    }
};
