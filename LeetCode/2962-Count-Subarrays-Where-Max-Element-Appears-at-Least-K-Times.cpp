// 2962. Count Subarrays Where Max Element Appears at Least K Times

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size(), r = 0, cnt = 0;
        int mx = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        for(int l = 0; l < n; l++) {
            while(r < n && cnt < k) {
                cnt += nums[r] == mx;
                r++;
            }
            if(cnt == k) ans += n - r + 1;
            cnt -= nums[l] == mx;
        }
        return ans;
    }
};
