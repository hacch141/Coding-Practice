// 2444. Count Subarrays With Fixed Bounds

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size(), bdi = -1, mni = -1, mxi = -1;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] < minK || nums[i] > maxK) bdi = i;
            if(nums[i] == minK) mni = i;
            if(nums[i] == maxK) mxi = i;
            ans += max(0, min(mni, mxi) - bdi);
        }
        return ans;
    }
};
