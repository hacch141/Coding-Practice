// 2779. Maximum Beauty of an Array After Applying Operation

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, ans = 0;
        sort(nums.begin(), nums.end());
        for(int r = 0; r < n; r++) {
            while(nums[r] - nums[l] > 2 * k) l++;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
