// 3264. Final Array State After K Multiplication Operations I

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        while(k--) {
            int mnInd = -1, mn = INT_MAX;
            for(int i = 0; i < n; i++) {
                if(nums[i] < mn) {
                    mn = nums[i];
                    mnInd = i;
                }
            }
            nums[mnInd] *= multiplier;
        }
        return nums;
    }
};
