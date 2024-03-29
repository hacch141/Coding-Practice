// 2966. Divide Array Into Arrays With Max Difference

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        vector<int> v;
        for(int i = 2; i < n; i += 3) {
            if(nums[i] - nums[i - 2] <= k) {
                ans.push_back({nums[i - 2], nums[i - 1], nums[i]});
            }
            else {
                return {};
            }
        }

        return ans;
    }
};
