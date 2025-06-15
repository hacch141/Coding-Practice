// 55. Jump Game

// Rec
class Solution {
public:
    int dp[10001];

    bool solve(int ind, int& n, vector<int>& nums) {
        if(ind >= n - 1) return true;

        if(dp[ind] != -1) return dp[ind];

        bool f = false;
        for(int i = 1; i <= nums[ind]; i++) {
            if(solve(ind + i, n, nums)) {
                f = true;
                break;
            }
        }

        return dp[ind] = f;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, nums);
    }
};

// DP
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), mx = nums[0];
        for(int i = 0; i < n; i++) {
            if(i > mx) return false;
            mx = max(mx, i + nums[i]);
        }
        return true;
    }
};
