// 2200. Find All K-Distant Indices in an Array

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size(), prev = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == key) prev = i;
            else if(prev != - 1 && i - prev <= k) {
                nums[i] = -1;
            }
        }
        prev = -1;
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] == key) prev = i;
            else if(prev != - 1 && prev - i <= k) {
                nums[i] = -1;
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(nums[i] == -1 || nums[i] == key) ans.push_back(i);
        }

        return ans;
    }
};
