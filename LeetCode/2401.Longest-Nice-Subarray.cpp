// 2401. Longest Nice Subarray

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), mask = 0, l = 0, ans = 0;
        for(int r = 0; r < n; r++) {
            while(mask & nums[r]) {
                mask -= nums[l];
                l++;
            }
            mask += nums[r];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
