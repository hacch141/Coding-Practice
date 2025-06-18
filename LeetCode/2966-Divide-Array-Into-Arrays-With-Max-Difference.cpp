// 2966. Divide Array Into Arrays With Max Difference

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i += 3) {
            int mx = max({nums[i], nums[i + 1], nums[i + 2]});
            int mn = min({nums[i], nums[i + 1], nums[i + 2]});
            if(mx - mn > k) return {};
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return ans;
    }
};
