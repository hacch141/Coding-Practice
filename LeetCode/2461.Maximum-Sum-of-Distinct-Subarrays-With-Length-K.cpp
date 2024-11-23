// 2461. Maximum Sum of Distinct Subarrays With Length K

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0, ans = 0;
        map<int,int> mp;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            mp[nums[i]]++;
            if(i >= k) {
                sum -= nums[i - k];
                mp[nums[i - k]]--;
                if(mp[nums[i - k]] == 0) mp.erase(nums[i - k]);
            }
            if(mp.size() == k) ans = max(ans, sum);
        }
        return ans;
    }
};
