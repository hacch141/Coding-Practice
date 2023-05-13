// 2466. Count Ways To Build Good Strings

class Solution {
public:
  
    int mod = 1e9+7;

    int solve(int len, int& low, int& high, int& zero, int& one, vector<int>& dp) {

        if(len>high) return 0;
        if(dp[len] != -1) return dp[len];

        int takeZero = solve(len+zero,low,high,zero,one,dp);
        int takeone = solve(len+one,low,high,zero,one,dp);

        if(len>=low && len<=high) return dp[len] = (1+takeone+takeZero)%mod;
        return dp[len] = (takeone+takeZero)%mod;
        
    }

    int countGoodStrings(int low, int high, int zero, int one) {    
        vector<int> dp(high+1,-1);
        return solve(0,low,high,zero,one,dp);
    }
};
