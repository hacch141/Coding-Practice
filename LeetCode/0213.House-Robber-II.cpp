// 213. House Robber II

class Solution {

private:
    int solve(vector<int>& nums) {
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

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> temp, temp2;
        for(int i=0; i<n; i++) {
            if(i!=0) temp.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(solve(temp),solve(temp2));
    }
};
