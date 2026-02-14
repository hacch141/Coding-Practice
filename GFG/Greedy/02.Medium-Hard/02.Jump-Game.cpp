// Jump Game

class Solution {
    public boolean canJump(int[] nums) {

        int maxReach = 0;

        for (int i = 0; i < nums.length && i <= maxReach; i++) {
            maxReach = Math.max(maxReach, i + nums[i]);
        }

        return maxReach >= nums.length - 1;
    }
}

// ===============================================================

class Solution {
public:

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0; i<n && i<=maxi; i++) {
            maxi = max(maxi , i+nums[i]);
        }

        return maxi >= n-1;
    }
};
// T : O(N)
// S : O(1)


class Solution {
public:

    bool solve(int ind, int& n, vector<int>& nums, vector<int>& dp) {
        if(ind == n-1) return true;
        if(ind>n) return false;

        if(dp[ind] != -1) return dp[ind];

        bool curr = false;
        for(int i=1; i<=nums[ind]; i++) {
            curr |= solve(i+ind , n , nums , dp);
            if(curr) break;
        }

        return dp[ind] = curr;   
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(0,n,nums,dp);
    }
};
