// 2461. Maximum Sum of Distinct Subarrays With Length K

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, total = 0, l = 0, r = 0, n = nums.size();
        unordered_map<int,int> mp;

        for(r=0; r<n; r++) {
            while(l<r && (mp.find(nums[r]) != mp.end() || (r-l+1) > k)) {
                mp.erase(nums[l]);
                total -= nums[l];
                l++;
            }

            total += nums[r];
            mp[nums[r]]++;

            if((r-l+1) == k) {
                ans = max(ans,total);
            }
        }

        return ans;
    }
};
