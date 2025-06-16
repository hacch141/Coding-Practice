// 2016. Maximum Difference Between Increasing Elements

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> mx(n, INT_MIN);
        mx[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            mx[i] = max(mx[i + 1], nums[i]);
        }

        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(mx[i] - nums[i] > 0) ans = max(ans, mx[i] - nums[i]);
        }

        return ans;
    }
};
