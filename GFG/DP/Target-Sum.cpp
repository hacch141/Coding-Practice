class Solution {
    
  private:
    int solve(int sum, vector<int>&A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int> (sum+1,0));
        if(A[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(A[0] != 0 && A[0]<=sum) dp[0][A[0]] = 1;
        
        for(int i=1; i<n; i++) {
            for(int target=0; target<=sum; target++) {
                int notpick = dp[i-1][target];
                int pick = 0;
                if(A[i] <= target) {
                    pick = dp[i-1][target-A[i]];
                }
                dp[i][target] = pick + notpick;
            }
        }
        return dp[n-1][sum];
    }
    
  public:
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int total = 0;
        for(auto i : A) total += i;
        if(total-target<0 || (total-target)%2==1) return 0;
        int sum = (total-target)/2;
        return solve(sum,A);
    }
};
