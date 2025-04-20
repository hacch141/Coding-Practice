// 2563. Count the Number of Fair Pairs

class Solution {
public:
    long long countFairPairsTill(vector<int>& nums, int till) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long cnt = 0;

        for (int r = 0; r < n; ++r) {
            // We want to find count of i < r such that nums[i] + nums[r] <= till
            // That means: nums[i] <= till - nums[r]
            int maxVal = till - nums[r];
            int idx = upper_bound(nums.begin(), nums.begin() + r, maxVal) - nums.begin();
            cnt += idx;
        }

        return cnt;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        return countFairPairsTill(nums, upper) - countFairPairsTill(nums, lower - 1);
    }
};

// =====================================================================

class Solution {
public:
    long long countFairPairsTill(vector<int>& nums, int till) {
        int left = 0, right = nums.size() - 1;
        long long cnt = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum <= till) {
                cnt += (right - left);
                left++;
            } else {
                right--;
            }
        }
        return cnt;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countFairPairsTill(nums, upper) - countFairPairsTill(nums, lower - 1);
    }
};
