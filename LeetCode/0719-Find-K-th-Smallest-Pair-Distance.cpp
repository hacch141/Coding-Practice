// 719. Find K-th Smallest Pair Distance
class Solution {
public:

    bool ok(int mid, vector<int>& nums, int& k) {
        int n = nums.size(), l = 0, cnt = 0;
        for(int r = 0; r < n; r++) {
            while(l < r && nums[r] - nums[l] > mid) {
                l++;
            }
            cnt += r - l;
        }
        return cnt >= k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size(), l = 0, h = nums[n - 1], ans = 0;
        while(l <= h) {
            int m = (h - l) / 2 + l;
            if(ok(m, nums, k)) {
                ans = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
};
