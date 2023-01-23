// 416. Partition Equal Subset Sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        for(auto i : nums) k += i;
        // if total sum is odd then it's not possible 
        if(k%2 == 1) return false;
        vector<bool> dp(k+1,0), curr(k+1,0);
        dp[0] = curr[0] = true;
        if(nums[0] <= k) dp[nums[0]] = true;
        for(int i=1; i<n; i++) {
            for(int target = 1; target<=k; target++) {
                bool notpick = dp[target];
                bool pick = false;
                if(nums[i] <= target) pick = dp[target-nums[i]];
                curr[target] = notpick | pick;
            }
            dp = curr;
        }
        // if k/2 is possible then (k-(k/2)) is also possible 
        // Hence there are two equal subset sum
        return dp[k/2];
    }
};
