// 2460. Apply Operations to an Array

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }

        int ind = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                ind = max(ind, i);
                while(ind < n && nums[ind] == 0) {
                    ind++;
                }
                if(ind < n) swap(nums[i], nums[ind]);
            }
        }

        return nums;
    }
};
