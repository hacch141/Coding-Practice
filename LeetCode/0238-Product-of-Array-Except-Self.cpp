// 238. Product of Array Except Self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int prefMul = 1, suffMul = 1;
        for(int i = 0; i < n; i++) {
            ans[i] *= prefMul;
            prefMul *= nums[i];
        }
        for(int i = n - 1; i >= 0; i--) {
            ans[i] *= suffMul;
            suffMul *= nums[i];
        }
        return ans;
    }
};
