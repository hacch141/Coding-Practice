// 2616. Minimize the Maximum Difference of Pairs

class Solution {
public:
    bool ok(int mid, vector<int>& nums, int p) {
        int n = nums.size(), cnt = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i - 1] <= mid) {
                cnt++;
                i++;
            }
        }
        return cnt >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, h = 1e9, ans = 0;
        while(l <= h) {
            int m = (h - l) / 2 + l;
            if(ok(m, nums, p)) {
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
