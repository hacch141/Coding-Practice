// 1498. Number of Subsequences That Satisfy the Given Sum Condition

class Solution {
public:
    int MOD = 1e9 + 7;

    int num_pow(long long num, long long pow, long long mod) {
        long long ans = 1;
        while(pow) {
            if(pow & 1) {
                ans = (ans * num) % MOD;
            }
            pow >>= 1;
            num = (num * num) % MOD;
        }
        return (int)ans;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        int l = 0, r = n - 1;
        while(l <= r) {
            if(nums[l] + nums[r] <= target) {
                ans = (ans + num_pow(2, r - l, MOD)) % MOD;
                l++;
            }
            else {
                r--;
            }
        }
        return ans;
    }
};

// Binary Search

class Solution {
public:
    int MOD = 1e9 + 7;

    int get_ind(vector<int>& nums, int val) {
        int n = nums.size();
        int l = 0, h = n - 1, ind = -1;
        while(l <= h) {
            int m = (h - l) / 2 + l;
            if(nums[m] <= val) {
                ind = m;
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }
        return ind;
    }

    int num_pow(long long num, long long pow, long long mod) {
        long long ans = 1;
        while(pow) {
            if(pow & 1) {
                ans = (ans * num) % MOD;
            }
            pow >>= 1;
            num = (num * num) % MOD;
        }
        return (int)ans;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            int rem = target - nums[i];
            int ind = get_ind(nums, rem);
            if(ind >= i) ans = (ans + num_pow(2, ind - i, MOD)) % MOD;
        }
        return ans;
    }
};
