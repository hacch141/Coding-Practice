// 1458. Max Dot Product of Two Subsequences

class Solution {
public:

    int solve(int i, int j, int& n, int& m, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if(i==n || j==m) {
            return -1e9;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int curr = nums1[i]*nums2[j];
        int take = (nums1[i]*nums2[j]) + solve(i+1 , j+1 , n , m , nums1 , nums2 , dp);
        int nottake1 = solve(i+1 , j , n , m , nums1 , nums2 , dp);
        int nottake2 = solve(i , j+1 , n , m , nums1 , nums2 , dp);

        return dp[i][j] = max(curr,max(take,max(nottake1 , nottake2)));
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1 , -1));
        return solve(0,0,n,m,nums1,nums2,dp);
    }
};
