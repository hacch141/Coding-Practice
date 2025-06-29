// 1035. Uncrossed Lines

class Solution {
public:
    int solve(int ind1, int n1, int ind2, int n2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if(ind1 == n1 || ind2 == n2) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if(nums1[ind1] == nums2[ind2]) return dp[ind1][ind2] = 1 + solve(ind1 + 1, n1, ind2 + 1, n2, nums1, nums2, dp);

        int left = solve(ind1 + 1, n1, ind2, n2, nums1, nums2, dp);
        int right = solve(ind1, n1, ind2 + 1, n2, nums1, nums2, dp);

        return dp[ind1][ind2] = max(left, right);
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return solve(0, n1, 0, n2, nums1, nums2, dp);
    }
};

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                if(nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n1][n2];
    }
};
