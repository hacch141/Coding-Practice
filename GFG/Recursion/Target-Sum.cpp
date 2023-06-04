// Target Sum

class Solution {
  public:
  
    int solve(int idx, int& n, vector<int>&A, int curr, int& target, vector<vector<int>>& dp, int& add) {
        if(idx==n) {
            return curr==target ? 1 : 0;
        }
        
        if(dp[idx][curr+add] != -1) return dp[idx][curr+add];
        
        int take = solve(idx+1,n,A,curr+A[idx],target,dp,add);
        int remove = solve(idx+1,n,A,curr-A[idx],target,dp,add);
        return dp[idx][curr+add] = take+remove;
    }
  
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int n = A.size();
        int curr = 0;
        int sum = 0;
        for(auto i : A) sum += i;
        vector<vector<int>> dp(n,vector<int>((2*sum) + 2,-1));
        return solve(0,n,A,curr,target,dp,sum);
    }
};
