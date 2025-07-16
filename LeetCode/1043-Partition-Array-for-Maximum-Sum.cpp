// 1043. Partition Array for Maximum Sum

// Bottom Up
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++) {
            int mx = arr[i];
            for(int j = i; j >= 0 && i - j + 1 <= k; j--) {
                mx = max(mx, arr[j]);
                dp[i] = max(dp[i], ((i - j + 1) * mx) + (j - 1 >= 0 ? dp[j - 1] : 0));
            }
        }
        return dp[n - 1];
    }
};

// Rec
class Solution {
public:
    int solve(int ind, int n, vector<int>& nums, int k, vector<int>& dp) {
        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int mx = nums[ind], ans = 0;
        for(int i = ind; i < min(n, ind + k); i++) {
            mx = max(mx, nums[i]);
            ans = max(ans, (mx * (i - ind + 1) + solve(i + 1, n, nums, k, dp)));
        }
        return dp[ind] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, n, arr, k, dp);
    }
};
