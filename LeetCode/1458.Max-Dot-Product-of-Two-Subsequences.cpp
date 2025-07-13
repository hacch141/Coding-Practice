// 1458. Max Dot Product of Two Subsequences

class Solution {
public:
    int solve(int ind1, int ind2, int n1, int  n2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if(ind1 == n1 || ind2 == n2) return -1e9;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int curr = nums1[ind1] * nums2[ind2];
        int take = curr + solve(ind1 + 1, ind2 + 1, n1, n2, nums1, nums2, dp);
        int nottake1 = solve(ind1 + 1, ind2, n1, n2, nums1, nums2, dp);
        int nottake2 = solve(ind1, ind2 + 1, n1, n2, nums1, nums2, dp);
        return dp[ind1][ind2] = max({curr, take, nottake1, nottake2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return solve(0, 0, n1, n2, nums1, nums2, dp);
    }
};


class Solution {
public:
    int solve(int ind1, int ind2, int n1, int  n2, bool taken, vector<int>& nums1, vector<int>& nums2, vector<vector<vector<int>>>& dp) {
        if(ind1 == n1 || ind2 == n2) return taken ? 0 : -1e9;

        if(dp[ind1][ind2][taken] != -1) return dp[ind1][ind2][taken];

        int nottake = solve(ind1 + 1, ind2, n1, n2, taken, nums1, nums2, dp);
        int take = -1e9;
        for(int i = ind2; i < n2; i++) {
            take = max(take, nums1[ind1] * nums2[i] + solve(ind1 + 1, i + 1, n1, n2, true, nums1, nums2, dp));
        }
        return dp[ind1][ind2][taken] = max(take, nottake);
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<vector<int>>> dp(n1, vector<vector<int>>(n2, vector<int>(2, -1)));
        return solve(0, 0, n1, n2, false, nums1, nums2, dp);
    }
};
