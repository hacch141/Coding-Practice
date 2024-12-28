// 689. Maximum Sum of 3 Non-Overlapping Subarrays

class Solution {
public:
    int get_sum(vector<int>& pref, int l, int r) {
        int sum = pref[r];
        if(l > 0) sum -= pref[l - 1];
        return sum;
    }

    int helper(int ind, int& n, int& k, int count, vector<int>& pref, vector<vector<int>>& dp) {
        if(count == 0 || ind + k - 1 >= n) return 0;
        if(dp[ind][count] != -1) return dp[ind][count];
        int take = get_sum(pref, ind, ind + k - 1) + helper(ind + k, n, k, count - 1, pref, dp);
        int nottake = helper(ind + 1, n, k, count, pref, dp);
        return dp[ind][count] = max(take, nottake);
    }

    void solve(int ind, int& n, int& k, int count, vector<int>& pref, vector<int>& ans, vector<vector<int>>& dp) {
        if(count == 0 || ind + k - 1 >= n) return;
        int take = get_sum(pref, ind, ind + k - 1) + helper(ind + k, n, k, count - 1, pref, dp);
        int nottake = helper(ind + 1, n, k, count, pref, dp);
        if(take >= nottake) {
            ans.push_back(ind);
            solve(ind + k, n, k, count - 1, pref, ans, dp);
        }
        else {
            solve(ind + 1, n, k, count, pref, ans, dp);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n, 0);
        for(int i = 0; i < n; i++) {
            if(i > 0) pref[i] += pref[i - 1];
            pref[i] += nums[i];
        }
        vector<int> ans;
        vector<vector<int>> dp(n, vector<int>(4, -1));
        solve(0, n, k, 3, pref, ans, dp);
        return ans;
    }
};
