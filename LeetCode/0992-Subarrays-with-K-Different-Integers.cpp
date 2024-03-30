// 992. Subarrays with K Different Integers

class Solution {
public:

    int atMostK(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, ans = 0;
        map<int,int> mp;
        for(int r = 0; r < n; r++) { 
            mp[nums[r]]++;
            while(l <= r && mp.size() > k) {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
