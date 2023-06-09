// Partition Equal Subset Sum


// Memoization
class Solution{
public:

    bool solve(int idx, int sum, int arr[], vector<vector<int>>& dp) {
        if(sum==0) return true;
        if(idx==0) return arr[0]==sum;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        bool nottake = solve(idx-1,sum,arr,dp);
        bool take = false;
        if(arr[idx]<=sum) take = solve(idx-1,sum-arr[idx],arr,dp);
        
        return dp[idx][sum] = take | nottake;
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0; i<N; i++) sum += arr[i];
        if(sum%2==1) return 0;
        sum /= 2;
        vector<vector<int>> dp(N, vector<int>(sum+1,-1));
        return solve(N-1,sum,arr,dp);
    }
};



// Tabulation
class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int k = 0;
        for(int i=0; i<N; i++) k += arr[i];
        if(k%2 == 1) return false;
        vector<bool> dp(k+1,0), curr(k+1,0);
        dp[0] = curr[0] = true;
        if(arr[0] <= k) dp[arr[0]] = true;
        for(int i=1; i<N; i++) {
            for(int target = 1; target <= k; target++) {
                bool notpick = dp[target];
                bool pick = false;
                if(arr[i] <= target) pick = dp[target-arr[i]];
                curr[target] = pick | notpick;
            }
            dp = curr;
        }
        return dp[k/2];
    }
};
