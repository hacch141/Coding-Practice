// Target Sum

// Recursion
int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
     if(ind == 0) {
        if(target==0 && arr[0]==0) return 2;
        if(target==0 || target == arr[0]) return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1) return dp[ind][target];
        
    int notTaken = countPartitionsUtil(ind-1,target,arr,dp);
    int taken = 0;
    if(arr[ind]<=target) {
        taken = countPartitionsUtil(ind-1,target-arr[ind],arr,dp);
    }   
    return dp[ind][target]= (notTaken + taken);
}

int targetSum(int n,int target, vector<int>& arr){
    int totSum = 0;
    for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-target<0) return 0;
    if((totSum-target)%2==1) return 0;
    
    int s2 = (totSum-target)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return countPartitionsUtil(n-1,s2,arr,dp);
}

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
