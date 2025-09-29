// 611. Valid Triangle Number

class Solution {
    int getRightMost(int l, int r, int[] nums, int sum) {
        int ind = l - 1;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (nums[m] < sum) {
                ind = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return ind;
    }

    public int triangleNumber(int[] nums) {
        int n = nums.length, ans = 0;
        Arrays.sort(nums);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = nums[i] + nums[j];
                int r = getRightMost(j + 1, n - 1, nums, sum);
                ans += r - j;
            }
        }
        return ans;
    }
}

class Solution {
    public int triangleNumber(int[] nums) {
        int n = nums.length, ans = 0;
        if (n < 3) return 0;
        Arrays.sort(nums);
        for (int i = 2; i < n; i++) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    ans += r - l;
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return ans;
    }
}
