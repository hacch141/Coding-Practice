// Subset Sum Problem

// Memoization
class Solution{   
public:

    bool solve(int idx, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if(sum==0) return true;
        if(idx==0) return (arr[0]==sum);
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        bool nottake = solve(idx-1,sum,arr,dp);
        bool take = false;
        if(arr[idx]<=sum) take = solve(idx-1,sum-arr[idx],arr,dp);
        
        return dp[idx][sum] = take | nottake;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        return solve(n-1,sum,arr,dp);
    }
};
// T : O(N*sum)
// S : O(N*sum)


// Tabulaion
class Solution{   
public:

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1,false));
        for(int i=0; i<n; i++) dp[i][0] = true;
        dp[0][arr[0]] = true;
        
        for(int i=1; i<n; i++) {
            for(int target=1; target<=sum; target++) {
                bool nottake = dp[i-1][target];
                bool take = false;
                if(arr[i]<=target) take = dp[i-1][target-arr[i]];
                dp[i][target] = take | nottake;
            }
        }
        
        return dp[n-1][sum];
    }
};
// T : O(N*sum)
// S : O(N*sum)


// Optimization
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<bool> dp(sum+1,0), curr(sum+1,0);
        dp[0] = curr[0] = true;
        if(arr[0] <= sum) dp[arr[0]] = true;
        for(int i=1; i<n; i++) {
            for(int target=1; target<=sum; target++) {
                bool notpick = dp[target];
                bool pick = false;
                if(arr[i] <= target) pick = dp[target-arr[i]];
                curr[target] = notpick | pick;
            }
            dp = curr;
        }
        return dp[sum];
    }
};
