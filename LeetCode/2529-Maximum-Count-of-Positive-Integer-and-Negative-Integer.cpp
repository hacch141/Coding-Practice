// 2529. Maximum Count of Positive Integer and Negative Integer

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for(auto &i : nums) {
            pos += i > 0;
            neg += i < 0;
        }
        return max(pos, neg);
    }
};

// ======================================

class Solution {
public:
    int find_neg(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1, ans = -1;
        while(left <= right) {
            int mid = (right - left) / 2 + left;
            if(nums[mid] >= 0) {
                right = mid - 1;
            }
            else {
                ans = mid;
                left = mid + 1;
            }
        }
        return ans + 1;
    }

    int find_pos(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;
        while(left <= right) {
            int mid = (right - left) / 2 + left;
            if(nums[mid] <= 0) {
                left = mid + 1;
            }
            else {
                ans = mid;
                right = mid - 1;
            }
        }
        return n - ans;
    }

    int maximumCount(vector<int>& nums) {
        int neg = find_neg(nums), pos = find_pos(nums);
        return max(neg, pos);
    }
};

// =====================

class Solution {
public:
    int find_neg(vector<int>& nums) {
        int ind = upper_bound(nums.begin(), nums.end(), -1) - nums.begin();
        return ind;
    }

    int find_pos(vector<int>& nums) {
        int ind = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        return nums.size() - ind;
    }

    int maximumCount(vector<int>& nums) {
        int neg = find_neg(nums), pos = find_pos(nums);
        return max(neg, pos);
    }
};
