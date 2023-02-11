// 55. Jump Game



class Solution {

public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int i;
        for(i=1; i<n && i<=maxi; i++) {
            maxi = max(maxi,i+nums[i]);
        }
        return i==n;
    }
};


// =======================================================

class Solution {

private:
    bool solve(int i, int n, vector<int>& nums, vector<int>& dp) {
        if(i==n-1) return true;
        if(nums[i]==0) return false;
        if(dp[i] != -1) return dp[i];
        bool isJump = false;
        for(int jump=1; jump<=nums[i] && i+jump<n; jump++) {
            isJump = solve(i+jump,n,nums,dp);
            if(isJump) return true;
        }
        return dp[i] = isJump;
    }

public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==1) return true;
        vector<int> dp(n+1,-1);
        return solve(0,n,nums,dp);
    }
};
