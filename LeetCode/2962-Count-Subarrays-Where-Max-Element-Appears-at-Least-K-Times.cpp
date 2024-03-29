// 2962. Count Subarrays Where Max Element Appears at Least K Times

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = 0, n = nums.size(), l = 0, f = 0;
        for(auto i : nums) mx = max(mx, i);
        
        long long ans = 0;
        for(int r = 0; r < n; r++) {
            f += nums[r] == mx;
            while(l <= r && f >= k) {
                f -= nums[l] == mx;
                l++;
            }
            if(f == k - 1) ans += l;
        }
        return ans;
    }
};
