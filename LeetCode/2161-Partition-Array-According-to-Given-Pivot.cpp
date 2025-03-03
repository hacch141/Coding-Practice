// 2161. Partition Array According to Given Pivot

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), ptr = 0;
        vector<int> ans(n, pivot);
        for(int i = 0; i < n; i++) {
            if(nums[i] < pivot) {
                ans[ptr] = nums[i];
                ptr++;
            }
        }
        ptr = n - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] > pivot) {
                ans[ptr] = nums[i];
                ptr--;
            }
        }
        return ans;
    }
};
