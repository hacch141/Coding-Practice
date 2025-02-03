// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx = 1, curr = 1, n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                curr++;
            }
            else {
                mx = max(mx, curr);
                curr = 1;
            }
        }
        mx = max(mx, curr);

        curr = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i - 1]) {
                curr++;
            }
            else {
                mx = max(mx, curr);
                curr = 1;
            }
        }
        mx = max(mx, curr);

        return mx;
    }
};
