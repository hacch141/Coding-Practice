// 198. House Robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev = nums[0];
        for(int i=1; i<nums.size(); i++) {
            int pick = nums[i] + prev2;
            int notpick = 0 + prev;
            int curr = max(pick,notpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
