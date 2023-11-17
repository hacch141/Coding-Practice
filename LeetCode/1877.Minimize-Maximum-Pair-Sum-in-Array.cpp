// 1877. Minimize Maximum Pair Sum in Array

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int ans = -1;
        for(int i=0; i<n/2; i++) {
            ans = max(ans , nums[i] + nums[n-1-i]);
        }
        
        return ans;
    }
};
