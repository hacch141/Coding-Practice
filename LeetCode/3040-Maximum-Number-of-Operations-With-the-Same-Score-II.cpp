// 3040. Maximum Number of Operations With the Same Score II

class Solution {
public:
    
    
    
    int solve(int i, int j, int& sum, vector<int>& nums, vector<vector<int>>& dp) {
        int c1 = 0, c2 = 0, c3 = 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(i < j && nums[i] + nums[j] == sum) {
            c1 = 1 + solve(i + 1, j - 1, sum, nums, dp);
        }
        if(i + 1 < j && nums[i] + nums[i + 1] == sum) {
            c2 = 1 + solve(i + 2, j, sum, nums, dp);
        }
        if(i < j - 1 && nums[j] + nums[j - 1] == sum) {
            c3 = 1 + solve(i, j - 2, sum, nums, dp);
        }
        
        return dp[i][j] = max(c1, max(c2,c3));
    }
    
    int maxOperations(vector<int>& nums) {
        int ans = 0, n = nums.size();
        set<int> s;
        s.insert(nums[0] + nums[1]);
        s.insert(nums[n - 2] + nums[n - 1]);
        s.insert(nums[0] + nums[n - 1]);
        for(auto i : s) {
            vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
            ans = max(ans,solve(0, n - 1, i, nums, dp));
        }
        return ans;
    }
};
