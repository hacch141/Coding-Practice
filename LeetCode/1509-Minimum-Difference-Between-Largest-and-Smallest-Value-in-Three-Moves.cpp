// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves

class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size(), ans = INT_MAX;
        if(n <= 4) return 0;
        int r = n - 1 - 3;
        for(int l = 0; l < 4; l++) {
            ans = min(ans, nums[r] - nums[l]);
            r++;
        }
        return ans;
    }
};
