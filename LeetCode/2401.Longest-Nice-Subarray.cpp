// 2401. Longest Nice Subarray

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0, n = nums.size(), _or = 0, l = 0, r = 0;

        for(r=0; r<n; r++) {
            while((_or & nums[r]) != 0) {
                _or ^= nums[l];
                l++;
            }
            _or |= nums[r];
            ans = max(ans,r-l+1);
        }

        return ans;
    }
};
