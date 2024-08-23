// 3254. Find the Power of K-Size Subarrays I

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size(), l = 0;
        vector<int> ans;
        for(int r = 0; r < n; r++) {
            if(r != 0 && nums[r] != nums[r - 1] + 1) l = r;
            if(r - l + 1 > k) l++;
            if(r >= k - 1) {
                if(r - l + 1 == k) ans.push_back(nums[r]);
                else ans.push_back(-1);
            }
        }
        return ans;
    }
};
