// 2799. Count Complete Subarrays in an Array

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        map<int,int> mp, mp_curr;
        for(auto &i : nums) mp[i]++;

        int n = nums.size(), r = 0, ans = 0;
        for(int l = 0; l < n; l++) {
            while(r < n && mp_curr.size() != mp.size()) {
                mp_curr[nums[r]]++;
                r++;
            }
            if(mp_curr.size() == mp.size()) {
                ans += n - r + 1;
            }
            mp_curr[nums[l]]--;
            if(mp_curr[nums[l]] == 0) mp_curr.erase(nums[l]);
        }

        return ans;
    }
};
